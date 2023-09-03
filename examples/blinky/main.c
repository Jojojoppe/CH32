#include <ch32.h>
#include <hal/gpio.h>
#include <hal/system.h>
#include <hal/trace.h>

#define PIN_LED GPIO_BANK_D, 4

void delayTick(uint32_t n) {
  int32_t targend = STK_CNTL + n;
  while ((int32_t)STK_CNTL - targend < 0)
    ;
}

int main() {
  clockInit(CLOCK_CONFIG_DEFAULT);
  traceInit();

  // Enable system clock
  STK_CTLR_bits.STCLK = 1;
  STK_CTLR_bits.STE = 1;

  GpioHandle led;
  GpioConfig ledConfig = {
      .interruptMode = GPIO_INTERRUPT_NONE,
      .mode = GPIO_MODE_DIGITAL_OUTPUT,
      .outputMode = GPIO_OUTPUT_MODE_PUSH_PULL,
      .alternateFunction = false,
  };
  gpioInit(&led, &ledConfig, PIN_LED);

  for (;;) {
    delayTick(getClockFrequency() / 2);
    gpioSetDigital(&led, 1);
    delayTick(getClockFrequency() / 2);
    gpioSetDigital(&led, 0);
  }

  return 0;
}