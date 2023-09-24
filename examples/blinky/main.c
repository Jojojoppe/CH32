#include <ch32.h>
#include <hal/gpio.h>
#include <hal/system.h>
#include <hal/trace.h>

#define PIN_LED GPIO_BANK_D, 4

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

  for (;;) {
    delayTick(getClockFrequency());
#if defined(__DEBUG) && defined(CH32V003)
    tracePut("On\n");
#endif
    gpioSetDigital(&led, 1);
    delayTick(getClockFrequency());
#if defined(__DEBUG) && defined(CH32V003)
    tracePut("Off\n");
#endif
    gpioSetDigital(&led, 0);
  }

  return 0;
}