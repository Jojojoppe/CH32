/**
 * @file gpio.c
 * @author Joppe Blondel
 * @date 2023-09-03
 * @brief
 */
#include <ch32.h>
#include <hal/gpio.h>
#include <hal/trace.h>

typedef struct GpioBankRegisters {
  uint32_t CFGLR;
  uint32_t pad0;
  uint32_t INDR;
  uint32_t OUTDR;
  uint32_t BSHR;
  uint32_t BCR;
  uint32_t LCKR;
} GpioBankRegisters __attribute__((packed));

static GpioBankRegisters *gpioBankRegisters[] = {
    (GpioBankRegisters *)&GPIOA_CFGLR_bits,
    (GpioBankRegisters *)&GPIOC_CFGLR_bits,
    (GpioBankRegisters *)&GPIOD_CFGLR_bits,
};

#define GPIO_BANK_COUNT sizeof(gpioBankRegisters) / sizeof(GpioBankRegisters *)

#ifdef GPIO_USE_INTERRUPTS
static GpioHandle *interruptHandles[8U] = {NULL};
#endif

void gpioInit(GpioHandle *handle, GpioConfig *config, uint32_t bank,
              uint32_t pin) {
  handle->bank = bank;
  handle->pin = pin;
  handle->next = NULL;
  handle->callback = NULL;

  // Make sure the bank clock is on
  switch (bank) {
  case GPIO_BANK_A:
    RCC_APB2PCENR_bits.IOPAEN = 1;
    break;
  case GPIO_BANK_C:
    RCC_APB2PCENR_bits.IOPCEN = 1;
    break;
  case GPIO_BANK_D:
    RCC_APB2PCENR_bits.IOPDEN = 1;
    break;
  default:
    return;
  }

  gpioSetConfig(handle, config);

#ifdef GPIO_USE_INTERRUPTS
  // Make sure to enable the external interrupts
  PFIC_IENR1_bits.INTEN20 = 1;
#endif
}

void gpioSetConfig(GpioHandle *handle, GpioConfig *config) {
  // Set pin modus
  volatile GpioBankRegisters *bh = gpioBankRegisters[handle->bank];
  uint32_t mode = 0, conf = 0;
  uint32_t mask = 0xf << (4 * handle->pin);
  bool output = false;
  bool input = false;
  bool pupd = false;

  // Set mode and conf values
  switch (config->mode) {
  case GPIO_MODE_DIGITAL_OUTPUT:
    mode = 0b10; // 2MHz output mode
    output = true;
    break;
  case GPIO_MODE_DIGITAL_OUTPUT_FAST:
    mode = 0b11; // 50MHz output mode
    output = true;
    break;
  case GPIO_MODE_DIGITAL_INPUT:
  case GPIO_MODE_ANALOG_INPUT:
    mode = 0b00; // Input mode
    input = true;
    break;
  }

  if (output) {
    switch (config->outputMode) {
    case GPIO_OUTPUT_MODE_PUSH_PULL:
      conf = 0b00;
      break;
    case GPIO_OUTPUT_MODE_OPEN_DRAIN:
      conf = 0b01;
      break;
    }
    if (config->alternateFunction) {
      conf |= 0b10; // Set conf to multiplexed function mode
    }
  }

  if (input && config->mode != GPIO_MODE_ANALOG_INPUT) {
    switch (config->inputMode) {
    case GPIO_INPUT_MODE_NORMAL:
      conf = 0b01; // floating input
      break;
    case GPIO_INPUT_MODE_PULL_UP:
    case GPIO_INPUT_MODE_PULL_DOWN:
      conf = 0b10;
      pupd = true;
      break;
    }
  } else if (config->mode == GPIO_MODE_ANALOG_INPUT) {
    conf = 0b00;
  }

  // Make sure the alternate function clock is running
  if (config->alternateFunction ||
      config->interruptMode != GPIO_INTERRUPT_NONE) {
    RCC_APB2PCENR_bits.AFIOEN = 1;
  }

  // Shift to right position
  mode = mode << (4 * handle->pin);
  conf = conf << (4 * handle->pin + 2);

  bh->CFGLR &= ~mask;
  bh->CFGLR |= conf | mode;

  // Set pull-up/down configuration
  if (pupd && config->inputMode == GPIO_INPUT_MODE_PULL_UP) {
    bh->OUTDR |= 1 << handle->pin;
  } else if (pupd && config->inputMode == GPIO_INPUT_MODE_PULL_UP) {
    bh->OUTDR &= ~(1 << handle->pin);
  }

#ifdef GPIO_USE_INTERRUPTS
  // register/deregister pin interrupts
  if (config->interruptMode != GPIO_INTERRUPT_NONE &&
      input) { // Disable external interrupt
    EXTI_INTENR &= ~(1 << handle->pin);
    // Set mode
    if (config->interruptMode == GPIO_INTERRUPT_RISING ||
        config->interruptMode == GPIO_INTERRUPT_BOTH) {
      EXTI_RTENR |= 1 << handle->pin;
    } else {
      EXTI_RTENR &= ~(1 << handle->pin);
    }
    if (config->interruptMode == GPIO_INTERRUPT_FALLING ||
        config->interruptMode == GPIO_INTERRUPT_BOTH) {
      EXTI_FTENR |= 1 << handle->pin;
    } else {
      EXTI_FTENR &= ~(1 << handle->pin);
    }
    // Set external interrupt to current bank
    uint32_t extix = 0;
    switch (handle->bank) {
    case GPIO_BANK_A:
      extix = 0;
      break;
    case GPIO_BANK_C:
      extix = 2;
      break;
    case GPIO_BANK_D:
      extix = 3;
      break;
    }
    extix = extix << (2 * handle->pin);
    uint32_t extix_mask = 3 << handle->pin;
    AFIO_EXTICR &= ~extix_mask;
    AFIO_EXTICR |= extix;
    // Save the handle in the interrupt array
    interruptHandles[handle->pin] = handle;
    // Enable external interrupt
    EXTI_INTENR |= 1 << handle->pin;
  }
#endif
}

#ifdef GPIO_USE_INTERRUPTS
void gpioRegisterInterruptCallback(GpioHandle volatile *handle,
                                   GpioInterruptCallback callback,
                                   void *userData) {
  handle->callback = callback;
  handle->userData = userData;
}
#endif

void gpioSetDigital(GpioHandle *handle, uint32_t value) {
  volatile GpioBankRegisters *bh = gpioBankRegisters[handle->bank];
  if (value != 0) {
    bh->BSHR = 1 << handle->pin;
    bh->BSHR = 0;
  } else {
    bh->BCR = 1 << handle->pin;
    bh->BCR = 0;
  }
}

uint32_t gpiogetDigital(GpioHandle *handle) {
  volatile GpioBankRegisters *bh = gpioBankRegisters[handle->bank];
  uint32_t input = (bh->INDR) >> handle->pin;
  return ((input & 1) != 0) ? 1 : 0;
}

#ifdef GPIO_USE_INTERRUPTS
void _EXTI7_0_Handler() __attribute__((interrupt));
void _EXTI7_0_Handler() {
  uint32_t intfr = EXTI_INTFR;
  // Acknowledge the interrupt
  EXTI_INTFR = intfr;
  // Call callbacks
  for (uint32_t i = 0; i < 8; i++) {
    if ((intfr & (1 << i)) != 0 && interruptHandles[i]->callback != NULL) {
      GpioHandle *handle = interruptHandles[i];
      handle->callback(handle, handle->userData);
    }
  }
}
#endif
