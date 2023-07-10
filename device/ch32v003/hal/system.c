/**
 * @file system.c
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief
 */
#include <ch32.h>
#include <hal/system.h>

static uint32_t clockFrequency;

void clockInit(enum ClockConfiguration clockConfiguration) {
  // Make sure to turn off PLL
  RCC_CTLR_bits.PLLON = 0;
  while (RCC_CTLR_bits.PLLRDY == 1)
    ;

  switch (clockConfiguration) {
  case CLOCK_CONFIG_DEFAULT:
  default:
    RCC_CFGR0_bits.HPRE = 0;   // No AHB scaling
    RCC_CFGR0_bits.PLLSRC = 0; // HSI source for PLL
    RCC_CTLR_bits.PLLON = 1;   // Turn on PLL
    while (RCC_CTLR_bits.PLLRDY == 0)
      ;
    RCC_CFGR0_bits.SW = RCC_SYSCLK_SRC_PLL; // Set SYSCLK to PLL
    while (RCC_CFGR0_bits.SWS != RCC_SYSCLK_SRC_PLL)
      ;
    clockFrequency = 48000000;
    break;
  }
}

uint32_t getClockFrequency(){
  return clockFrequency;
}
