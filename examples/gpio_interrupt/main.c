#include <ch32.h>
#include <hal/gpio.h>
#include <hal/system.h>
#include <hal/trace.h>

#define PIN_LED GPIO_BANK_D, 4
#define PIN_INPUT GPIO_BANK_D, 5

static volatile uint32_t counter;

void inputInterrupt(GpioHandle *gpio, void *userData) {
  GpioHandle *led = userData;
  gpioSetDigital(led, 1);
  counter = 5000000;
}

int main() {
  clockInit(CLOCK_CONFIG_DEFAULT);

#if defined(__DEBUG) && defined(CH32V003)
  traceInit();
  traceWaitForDebugger();
  tracePut("Hello World!\r\n");
#endif

  GpioHandle led;
  GpioConfig ledConfig = {
      .interruptMode = GPIO_INTERRUPT_NONE,
      .mode = GPIO_MODE_DIGITAL_OUTPUT,
      .outputMode = GPIO_OUTPUT_MODE_PUSH_PULL,
      .alternateFunction = false,
  };
  gpioInit(&led, &ledConfig, PIN_LED);

  GpioHandle input;
  GpioConfig inputConfig = {
      .interruptMode = GPIO_INTERRUPT_RISING,
      .mode = GPIO_MODE_DIGITAL_INPUT,
      .inputMode = GPIO_INPUT_MODE_PULL_DOWN,
      .alternateFunction = false,
  };
  gpioInit(&input, &inputConfig, PIN_INPUT);
  gpioRegisterInterruptCallback(&input, inputInterrupt, (void *)&led);

  for (;;) {
    if (counter > 0) {
      while (counter) {
        counter--;
      }
      gpioSetDigital(&led, 0);
    }
  }

  return 0;
}