#include <ch32.h>
#include <stdint.h>

int main() {
  // Use PLL
  RCC_CFGR0 = 0;
  RCC_CLTR_bits.PLLON = 1;
  // Clear interupt ready flags
  RCC_INTR_bits.CSSC = 1;
  RCC_INTR_bits.PLLRDYC = 1;
  RCC_INTR_bits.HSERDYC = 1;
  RCC_INTR_bits.HSIRDYC = 1;
  RCC_INTR_bits.LSIRDYC = 1;
  // Wait for PLL to be locked
  while(RCC_CLTR_bits.PLLRDY==0);
  // Use PLL as system clock
  RCC_CFGR0_bits.SW = RCC_SYSCLK_SRC_PLL;
  // Wait for PLL to be set to output
  while(RCC_CFGR0_bits.SWS!=RCC_SYSCLK_SRC_PLL);

  // // Enable APB2 clocks for gpio B and D
  RCC_APB2PCENR_bits.IOPDEN = 1;

  GPIOD_CFGLR_bits.MODE4 = GPIO_MODE_OUTPUT_50MHZ;
  GPIOD_CFGLR_bits.CNF4 = GPIO_CNF_OUTPUT_PUSH_PULL;

  for (;;) {
    GPIOD_BSHR_bits.BS4 = 1;
    for (uint32_t i = 0; i < 0x100000; i++);
    GPIOD_BCR_bits.BR4 = 1;
    for (uint32_t i = 0; i < 0x100000; i++);
    GPIOD_OUTDR_bits.ODR4 ^= 1;
    for (uint32_t i = 0; i < 0x200000; i++);
    GPIOD_OUTDR_bits.ODR4 ^= 1;
    for (uint32_t i = 0; i < 0x200000; i++);
  }

  return 0;
}
