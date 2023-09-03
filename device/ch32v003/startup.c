#include <ch32.h>
#pragma optimize( "", off )

#ifdef CPLUSPLUS
// Method to call the C++ constructors
void __libc_init_array(void);
#endif

// Somewhere there is a main()
int main() __attribute__((used));

// If you don't override a specific handler, it will just spin forever.
void _DefaultIRQ_Handler(void) __attribute__((section(".text.vector_handler")));
void _DefaultIRQ_Handler(void) { asm volatile("1: j 1b"); }
#define DEFINTERRUPT(x)                                                        \
  void _##x##_Handler(void) __attribute__((section(".text.vector_handler")))       \
  __attribute__((weak, alias("_DefaultIRQ_Handler"))) __attribute__((used))

// All interrupt handlers point to the default IRQ handler
DEFINTERRUPT(NMI);
DEFINTERRUPT(HardFault);
DEFINTERRUPT(SysTick);
DEFINTERRUPT(SW);
DEFINTERRUPT(WWDG);
DEFINTERRUPT(PVD);
DEFINTERRUPT(FLASH);
DEFINTERRUPT(RCC);
DEFINTERRUPT(EXTI7_0);
DEFINTERRUPT(AWU);
DEFINTERRUPT(DMA1_CH1);
DEFINTERRUPT(DMA1_CH2);
DEFINTERRUPT(DMA1_CH3);
DEFINTERRUPT(DMA1_CH4);
DEFINTERRUPT(DMA1_CH5);
DEFINTERRUPT(DMA1_CH6);
DEFINTERRUPT(DMA1_CH7);
DEFINTERRUPT(ADC);
DEFINTERRUPT(I2C1_EV);
DEFINTERRUPT(I2C1_ER);
DEFINTERRUPT(USART1);
DEFINTERRUPT(SPI1);
DEFINTERRUPT(TIM1BRK);
DEFINTERRUPT(TIM1UP);
DEFINTERRUPT(TIM1TRG);
DEFINTERRUPT(TIM1CC);
DEFINTERRUPT(TIM2);

void IVT() __attribute__((naked)) __attribute((section(".init")))
__attribute((weak, alias("DefaultIVT")));
void DefaultIVT() __attribute__((naked)) __attribute((section(".init")));
void DefaultIVT() {
  asm volatile("\n\
	.align  2\n\
	.option   push;\n\
	.option   norvc;\n\
	j handle_reset\n\
	.word   0\n\
	.word   _NMI_Handler\n\
	.word   _HardFault_Handler\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   _SysTick_Handler\n\
	.word   0\n\
	.word   _SW_Handler\n\
	.word   0\n\
	.word   _WWDG_Handler\n\
	.word   _PVD_Handler\n\
	.word   _FLASH_Handler\n\
	.word   _RCC_Handler\n\
	.word   _EXTI7_0_Handler\n\
	.word   _AWU_Handler\n\
	.word   _DMA1_CH1_Handler\n\
	.word   _DMA1_CH2_Handler\n\
	.word   _DMA1_CH3_Handler\n\
	.word   _DMA1_CH4_Handler\n\
	.word   _DMA1_CH5_Handler\n\
	.word   _DMA1_CH6_Handler\n\
	.word   _DMA1_CH7_Handler\n\
	.word   _ADC_Handler\n\
	.word   _I2C1_EV_Handler\n\
	.word   _I2C1_ER_Handler\n\
	.word   _USART1_Handler\n\
	.word   _SPI1_Handler\n\
	.word   _TIM1BRK_Handler\n\
	.word   _TIM1UP_Handler\n\
	.word   _TIM1TRG_Handler\n\
	.word   _TIM1CC_Handler\n\
	.word   _TIM2_Handler\n\
  .option   pop;\n\
	");
}

void handle_reset() __attribute__((used, naked));
void handle_reset(){
  asm volatile("\n\
.option push\n\
.option norelax\n\
	la gp, __global_pointer$\n\
.option pop\n\
	la sp, _eusrstack\n"
#if __GNUC__ > 10
               ".option arch, +zicsr\n"
#endif
               // Setup the interrupt vector, processor status and INTSYSCR.
               "	li a0, 0x80\n\
	csrw mstatus, a0\n\
	li a3, 0x3\n\
	la a0, IVT\n\
	or a0, a0, a3\n\
	csrw mtvec, a0\n"
               :
               :
               : "a0", "a3", "memory");

  // Careful: Use registers to prevent overwriting of self-data.
  // This clears out BSS.
  asm volatile("	la a0, _sbss\n\
	la a1, _ebss\n\
	li a2, 0\n\
	bge a0, a1, 2f\n\
1:	sw a2, 0(a0)\n\
	addi a0, a0, 4\n\
	blt a0, a1, 1b\n\
2:"
               // This loads DATA from FLASH to RAM.
               "	la a0, _data_lma\n\
	la a1, _data_vma\n\
	la a2, _edata\n\
1:	beq a1, a2, 2f\n\
	lw a3, 0(a0)\n\
	sw a3, 0(a1)\n\
	addi a0, a0, 4\n\
	addi a1, a1, 4\n\
	bne a1, a2, 1b\n\
2:\n"
#ifdef CPLUSPLUS
               // Call __libc_init_array function
               "	call %0 \n\t"
               :
               : "i"(__libc_init_array)
               : "a0", "a1", "a2", "a3", "a4", "a5", "t0", "t1", "t2", "memory"
#else
               :
               :
               : "a0", "a1", "a2", "a3", "memory"
#endif
  );

  // set mepc to be main as the root app.
  asm volatile("	csrw mepc, %[main]\n"
               "	mret\n"
               :
               : [main] "r"(main));
}

#ifdef CPLUSPLUS
// This is required to allow pure virtual functions to be defined.
extern void __cxa_pure_virtual() {
  while (1)
    ;
}

// These magic symbols are provided by the linker.
extern void (*__preinit_array_start[])(void) __attribute__((weak));
extern void (*__preinit_array_end[])(void) __attribute__((weak));
extern void (*__init_array_start[])(void) __attribute__((weak));
extern void (*__init_array_end[])(void) __attribute__((weak));

void __libc_init_array(void) {
  size_t count;
  size_t i;

  count = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < count; i++)
    __preinit_array_start[i]();

  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i]();
}
#endif

#pragma optimize( "", on )
