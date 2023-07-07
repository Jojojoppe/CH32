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
  RCC_CFGR0_bits.SW = 2;
  // Wait for PLL to be set to output
  while(RCC_CFGR0_bits.SWS!=2);

  // // Enable APB2 clocks for gpio B and D
  RCC_APB2PCENR_bits.IOPDEN = 1;

  uint32_t *gpiob_cfghr = (uint32_t *)0x40010c04;
  uint32_t *gpiob_bshr = (uint32_t *)0x40010c10;
  uint32_t *gpiod_cfglr = (uint32_t *)0x40011400;
  uint32_t *gpiod_bshr = (uint32_t *)0x40011410;
  // push pull for D4 and B8
  *gpiob_cfghr &= ~(0b1111 << (4 * 0));
  *gpiob_cfghr |= 0b0001 << (4 * 0);
  *gpiod_cfglr &= ~(0b1111 << (4 * 4));
  *gpiod_cfglr |= 0b0001 << (4 * 4);

  for (;;) {
    *gpiob_bshr |= 1 << 8;
    *gpiod_bshr |= 1 << 4;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
    *gpiob_bshr |= (1 << (8 + 16));
    *gpiod_bshr |= (1 << (4 + 16));
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
  }

  return 0;
}
