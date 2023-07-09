#include <ch32.h>
#include <stdint.h>

void delayTick(uint32_t n) {
  int32_t targend = STK_CNTL + n;
  while ((int32_t)STK_CNTL - targend < 0)
    ;
}

int main() {
  // Use PLL on top of HSI
  // Disable scaling in fabric
  RCC_CFGR0_bits.HPRE = 0;
#ifdef CH32V203
  RCC_CFGR0_bits.PPRE1 = 0;
  RCC_CFGR0_bits.PPRE2 = 0;
#endif
  // Set PLL config
  RCC_CTLR_bits.PLLON = 0;
  while (RCC_CTLR_bits.PLLRDY == 1)
    ;
  RCC_CFGR0_bits.PLLSRC = 0;
#ifdef CH32V203
  RCC_CFGR0_bits.PLLXTPRE = 0;
  RCC_CFGR0_bits.PLLMUL = 10; // Set SYSCLK to 48MHz (Somehow times 2...)
#endif
  // Clear interupt ready flags
  RCC_INTR_bits.CSSC = 1;
  RCC_INTR_bits.PLLRDYC = 1;
  RCC_INTR_bits.HSERDYC = 1;
  RCC_INTR_bits.HSIRDYC = 1;
  RCC_INTR_bits.LSIRDYC = 1;
#ifdef CH32V203
  RCC_INTR_bits.LSERDYC = 1;
#endif
  // Enable PLL and wait until locked
  RCC_CTLR_bits.PLLON = 1;
  while (RCC_CTLR_bits.PLLRDY == 0)
    ;
  RCC_CFGR0_bits.SW = RCC_SYSCLK_SRC_PLL;
  while (RCC_CFGR0_bits.SWS != RCC_SYSCLK_SRC_PLL)
    ;

  // Enable system clock
  STK_CNTL = 0;
#ifdef CH32V203
  STK_CNTH = 0;
#endif
  STK_CTLR = 5;

#ifdef CH32V003
  RCC_APB2PCENR_bits.IOPDEN = 1;
  GPIOD_CFGLR_bits.MODE4 = GPIO_MODE_OUTPUT_50MHZ;
  GPIOD_CFGLR_bits.CNF4 = GPIO_CNF_OUTPUT_PUSH_PULL;
#endif
#ifdef CH32V203
  RCC_APB2PCENR_bits.IOPBEN = 1;
  GPIOB_CFGHR_bits.MODE8 = GPIO_MODE_OUTPUT_50MHZ;
  GPIOB_CFGHR_bits.CNF8 = GPIO_CNF_OUTPUT_PUSH_PULL;
#endif

  for (;;) {
#ifdef CH32V003
    GPIOD_OUTDR_bits.ODR4 ^= 1;
#endif
#ifdef CH32V203
    GPIOB_OUTDR_bits.ODR8 ^= 1;
#endif
    delayTick(48000000 / 2);
  }

  return 0;
}
