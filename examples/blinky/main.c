#include <ch32.h>
#include <hal/system.h>
#include <hal/trace.h>

#include <stdint.h>

void delayTick(uint32_t n) {
  int32_t targend = STK_CNTL + n;
  while ((int32_t)STK_CNTL - targend < 0)
    ;
}

int putchar(int c) {
  // 	while( !(USART1->STATR & USART_FLAG_TC));
  while (!USART_STATR_bits.TC)
    ;
  // 	USART1->DATAR = (const char)c;
  USART_DATAR = c;
  return 1;
}

int main() {
  clockInit(CLOCK_CONFIG_DEFAULT);

  traceInit();
  traceWaitForDebugger();

  // Enable system clock
  STK_CTLR_bits.STCLK = 1;
  STK_CTLR_bits.STE = 1;

  // D5/D6 are TX/RX
  // enable gpio+uart in APB2
  RCC_APB2PCENR_bits.USART1EN = 1;
  RCC_APB2PCENR_bits.IOPDEN = 1;
  // Set D5 @ 10MHz+func push pull
  AFIO_PCFR1_bits.USART1_RM = 0;
  AFIO_PCFR1_bits.USART1_RM1 = 0;
  GPIOD_CFGLR_bits.CNF5 = GPIO_CNF_OUTPUT_FUNC_PUSH_PULL;
  GPIOD_CFGLR_bits.MODE5 = GPIO_MODE_OUTPUT_10MHZ;
  AFIO_PCFR1_bits.USART1_RM = 0;
  AFIO_PCFR1_bits.USART1_RM1 = 0; // Default mapping to d5/d6
  USART_CTLR1_bits.M = 0;         // 8b
  USART_CTLR1_bits.PCE = 0;       // No parity check
  USART_CTLR1_bits.TE = 1;        // Enable transmit mode
  USART_CTLR2_bits.STOP = 0;      // 1 stopbit
  USART_CTLR3_bits.CTSE = 0;
  USART_CTLR3_bits.RTSE = 0;
  USART_BRR_bits.DIV_Fraction = 8;
  USART_BRR_bits.DIV_Mantissa = 312; // 9600 baud
  USART_CTLR1_bits.UE = 1;           // Enable UART

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
    putchar('B');
    tracePutChar('A');
  }
  return 0;
}