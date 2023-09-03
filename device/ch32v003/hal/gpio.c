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
  uint32_t INDR;
  uint32_t OUTDR;
  uint32_t BSHR;
  uint32_t BCR;
  uint32_t LCKR;
} GpioBankRegisters __attribute__((packed));

typedef struct _GpioBankHandle {
  uint32_t fallingEdge;
  uint32_t risingEdge;
  uint32_t lastValue;
} GpioBankHandle;

static volatile GpioBankRegisters *gpioBankRegisters[] = {
    (GpioBankRegisters *)&GPIOA_CFGLR_bits,
    (GpioBankRegisters *)&GPIOC_CFGLR_bits,
    (GpioBankRegisters *)&GPIOD_CFGLR_bits,
};

#define GPIO_BANK_COUNT sizeof(gpioBankRegisters) / sizeof(GpioBankRegisters *)

static GpioBankHandle gpioBankHandles[GPIO_BANK_COUNT] = {0};

void gpioInit(GpioHandle *handle, GpioConfig *config, uint32_t bank,
              uint32_t pin) {
  handle->bank = bank;
  handle->pin = pin;
  handle->next = NULL;

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
  default:
    return;
  }

  if (output) {
    switch (config->outputMode) {
    case GPIO_OUTPUT_MODE_PUSH_PULL:
      conf = 0b00;
      break;
    case GPIO_OUTPUT_MODE_OPEN_DRAIN:
      conf = 0b01;
      break;
    default:
      return;
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
    default:
      return;
    }
  } else if (config->mode == GPIO_MODE_ANALOG_INPUT) {
    conf = 0b00;
  }

  // Make sure the alternate function clock is running
  if (config->alternateFunction) {
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
}

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

uint32_t gpiogetDigital(GpioHandle *handle){
  volatile GpioBankRegisters *bh = gpioBankRegisters[handle->bank];
  return ((bh->INDR>>handle->pin)!=0) ? 1 : 0;
}
