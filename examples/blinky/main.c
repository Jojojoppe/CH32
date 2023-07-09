#include <ch32.h>
#include <stdint.h>

int main() {
// Use PLL
#ifdef CH32V203
  RCC_CFGR0_bits.PLLMUL = 15; // Set execution to 144MHz
#endif
  RCC_CLTR_bits.PLLON = 1;
  // Clear interupt ready flags
  RCC_INTR_bits.CSSC = 1;
  RCC_INTR_bits.PLLRDYC = 1;
  RCC_INTR_bits.HSERDYC = 1;
  RCC_INTR_bits.HSIRDYC = 1;
  RCC_INTR_bits.LSIRDYC = 1;
  // Wait for PLL to be locked
  while (RCC_CLTR_bits.PLLRDY == 0)
    ;
  // Use PLL as system clock
  RCC_CFGR0_bits.SW = RCC_SYSCLK_SRC_PLL;
  // Wait for PLL to be set to output
  while (RCC_CFGR0_bits.SWS != RCC_SYSCLK_SRC_PLL)
    ;

#ifdef CH32V003
  // // Enable APB2 clocks for gpio D
  RCC_APB2PCENR_bits.IOPDEN = 1;

  GPIOD_CFGLR_bits.MODE4 = GPIO_MODE_OUTPUT_50MHZ;
  GPIOD_CFGLR_bits.CNF4 = GPIO_CNF_OUTPUT_PUSH_PULL;

  for (;;) {
    GPIOD_OUTDR_bits.ODR4 ^= 1;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
    GPIOD_OUTDR_bits.ODR4 ^= 1;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
  }
#endif

#ifdef CH32V203
  // // Enable APB2 clocks for gpio B
  RCC_APB2PCENR_bits.IOPBEN = 1;

  GPIOB_CFGHR_bits.MODE8 = GPIO_MODE_OUTPUT_50MHZ;
  GPIOB_CFGHR_bits.CNF8 = GPIO_CNF_OUTPUT_PUSH_PULL;

  for (;;) {
    GPIOB_OUTDR_bits.ODR8 ^= 1;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
    GPIOB_OUTDR_bits.ODR8 ^= 1;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
  }
#endif

  return 0;
}
