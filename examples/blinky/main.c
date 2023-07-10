#include <ch32.h>
#include <hal/system.h>

#include <stdint.h>

void delayTick(uint32_t n) {
  int32_t targend = STK_CNTL + n;
  while ((int32_t)STK_CNTL - targend < 0)
    ;
}

int main() {
  clockInit(CLOCK_CONFIG_DEFAULT);

  // Enable system clock
  STK_CTLR_bits.STCLK = 1;
  STK_CTLR_bits.STE = 1;

  // D5/D6 are TX/RX
  // enable gpio+uart in APB2
  // Set D5 @ 10MHz+func push pull
  // usart1->ctlr1 = 8b no_parity mode_tx
  // usart1->ctlr2 = stopbits_1
  // usart1->ctlr3 = flow_control_none
  // usart1->brr = brr (115200)
  // usart1->ctlr1 += UE_Set
  // int putchar(int c){
  // 	while( !(USART1->STATR & USART_FLAG_TC));
  // 	USART1->DATAR = (const char)c;
  // 	return 1;
  // }

#ifdef CH32V003
  RCC_APB2PCENR_bits.IOPDEN = 1;
  GPIOD_CFGLR_bits.MODE4 = GPIO_MODE_OUTPUT_2MHZ;
  GPIOD_CFGLR_bits.CNF4 = GPIO_CNF_OUTPUT_PUSH_PULL;
#endif
#ifdef CH32V203
  RCC_APB2PCENR_bits.IOPBEN = 1;
  GPIOB_CFGHR_bits.MODE8 = GPIO_MODE_OUTPUT_2MHZ;
  GPIOB_CFGHR_bits.CNF8 = GPIO_CNF_OUTPUT_PUSH_PULL;
#endif

  for (;;) {
#ifdef CH32V003
    GPIOD_OUTDR_bits.ODR4 ^= 1;
#endif
#ifdef CH32V203
    GPIOB_OUTDR_bits.ODR8 ^= 1;
#endif
    delayTick(getClockFrequency() / 2);
  }
  return 0;
}