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
  void _##x##_Handler(void) __attribute__((section(".text.vector_handler")))   \
  __attribute__((weak, alias("_DefaultIRQ_Handler"))) __attribute__((used))

DEFINTERRUPT(NMI);
DEFINTERRUPT(HardFault);
DEFINTERRUPT(Ecall_M);
DEFINTERRUPT(Ecall_U);
DEFINTERRUPT(BreakPoint);
DEFINTERRUPT(SysTick);
DEFINTERRUPT(SW);
DEFINTERRUPT(WWDG);
DEFINTERRUPT(PVD);
DEFINTERRUPT(TAMPER);
DEFINTERRUPT(RTC);
DEFINTERRUPT(FLASH);
DEFINTERRUPT(RCC);
DEFINTERRUPT(EXTI0);
DEFINTERRUPT(EXTI1);
DEFINTERRUPT(EXTI2);
DEFINTERRUPT(EXTI3);
DEFINTERRUPT(EXTI4);
DEFINTERRUPT(DMA1_CH1);
DEFINTERRUPT(DMA1_CH2);
DEFINTERRUPT(DMA1_CH3);
DEFINTERRUPT(DMA1_CH4);
DEFINTERRUPT(DMA1_CH5);
DEFINTERRUPT(DMA1_CH6);
DEFINTERRUPT(DMA1_CH7);
DEFINTERRUPT(ADC1_2);
DEFINTERRUPT(USB_HP_CAN1_TX);
DEFINTERRUPT(USB_LP_CAN1_RX0);
DEFINTERRUPT(CAN1_RX1);
DEFINTERRUPT(CAN1_SCE);
DEFINTERRUPT(EXTI9_5);
DEFINTERRUPT(TIM1_BRK);
DEFINTERRUPT(TIM1_UP);
DEFINTERRUPT(TIM1_TRG_COM);
DEFINTERRUPT(TIM1_CC);
DEFINTERRUPT(TIM2);
DEFINTERRUPT(TIM3);
DEFINTERRUPT(TIM4);
DEFINTERRUPT(I2C1_EV);
DEFINTERRUPT(I2C1_ER);
DEFINTERRUPT(I2C2_EV);
DEFINTERRUPT(I2C2_ER);
DEFINTERRUPT(SPI1);
DEFINTERRUPT(SPI2);
DEFINTERRUPT(USART1);
DEFINTERRUPT(USART2);
DEFINTERRUPT(USART3);
DEFINTERRUPT(EXTI15_10);
DEFINTERRUPT(RTCAlarm);
DEFINTERRUPT(USBWakeUp);
DEFINTERRUPT(TIM8_BRK);
DEFINTERRUPT(TIM8_UP);
DEFINTERRUPT(TIM8_TRG_COM);
DEFINTERRUPT(TIM8_CC);
DEFINTERRUPT(RNG);
DEFINTERRUPT(FSMC);
DEFINTERRUPT(SDIO);
DEFINTERRUPT(TIM5);
DEFINTERRUPT(SPI3);
DEFINTERRUPT(UART4);
DEFINTERRUPT(UART5);
DEFINTERRUPT(TIM6);
DEFINTERRUPT(TIM7);
DEFINTERRUPT(DMA2_CH1);
DEFINTERRUPT(DMA2_CH2);
DEFINTERRUPT(DMA2_CH3);
DEFINTERRUPT(DMA2_CH4);
DEFINTERRUPT(DMA2_CH5);
DEFINTERRUPT(ETH);
DEFINTERRUPT(ETH_WKUP);
DEFINTERRUPT(CAN2_TX);
DEFINTERRUPT(CAN2_RX0);
DEFINTERRUPT(CAN2_RX1);
DEFINTERRUPT(OTG_FS);
DEFINTERRUPT(USBHSWakeUp);
DEFINTERRUPT(USBHS);
DEFINTERRUPT(DVP);
DEFINTERRUPT(UART6);
DEFINTERRUPT(UART7);
DEFINTERRUPT(UART8);
DEFINTERRUPT(TIM9_BRK);
DEFINTERRUPT(TIM9_UP);
DEFINTERRUPT(TIM9_TRG_COM);
DEFINTERRUPT(TIM9_CC);
DEFINTERRUPT(TIM10_BRK);
DEFINTERRUPT(TIM10_UP);
DEFINTERRUPT(TIM10_TRG_COM);
DEFINTERRUPT(TIM10_CC);
DEFINTERRUPT(DMA2_CH6);
DEFINTERRUPT(DMA2_CH7);
DEFINTERRUPT(DMA2_CH8);
DEFINTERRUPT(DMA2_CH9);
DEFINTERRUPT(DMA2_CH10);
DEFINTERRUPT(DMA2_CH11);

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
  .word   _Ecall_M_Handler\n\
	.word   0\n\
	.word   0\n\
  .word   _Ecall_U_Handler\n\
  .word   _NMI_Handler\n\
  .word   _BreakPoint_Handler\n\
	.word   0\n\
	.word   0\n\
  .word   _SysTick_Handler\n\
	.word   0\n\
  .word   _SW_Handler\n\
	.word   0\n\
  .word   _NMI_Handler\n\
  .word   _HardFault_Handler\n\
  .word   _Ecall_M_Handler\n\
  .word   _Ecall_U_Handler\n\
  .word   _BreakPoint_Handler\n\
  .word   _SysTick_Handler\n\
  .word   _SW_Handler\n\
  .word   _WWDG_Handler\n\
  .word   _PVD_Handler\n\
  .word   _TAMPER_Handler\n\
  .word   _RTC_Handler\n\
  .word   _FLASH_Handler\n\
  .word   _RCC_Handler\n\
  .word   _EXTI0_Handler\n\
  .word   _EXTI1_Handler\n\
  .word   _EXTI2_Handler\n\
  .word   _EXTI3_Handler\n\
  .word   _EXTI4_Handler\n\
  .word   _DMA1_CH1_Handler\n\
  .word   _DMA1_CH2_Handler\n\
  .word   _DMA1_CH3_Handler\n\
  .word   _DMA1_CH4_Handler\n\
  .word   _DMA1_CH5_Handler\n\
  .word   _DMA1_CH6_Handler\n\
  .word   _DMA1_CH7_Handler\n\
  .word   _ADC1_2_Handler\n\
  .word   _USB_HP_CAN1_TX_Handler\n\
  .word   _USB_LP_CAN1_RX0_Handler\n\
  .word   _CAN1_RX1_Handler\n\
  .word   _CAN1_SCE_Handler\n\
  .word   _EXTI9_5_Handler\n\
  .word   _TIM1_BRK_Handler\n\
  .word   _TIM1_UP_Handler\n\
  .word   _TIM1_TRG_COM_Handler\n\
  .word   _TIM1_CC_Handler\n\
  .word   _TIM2_Handler\n\
  .word   _TIM3_Handler\n\
  .word   _TIM4_Handler\n\
  .word   _I2C1_EV_Handler\n\
  .word   _I2C1_ER_Handler\n\
  .word   _I2C2_EV_Handler\n\
  .word   _I2C2_ER_Handler\n\
  .word   _SPI1_Handler\n\
  .word   _SPI2_Handler\n\
  .word   _USART1_Handler\n\
  .word   _USART2_Handler\n\
  .word   _USART3_Handler\n\
  .word   _EXTI15_10_Handler\n\
  .word   _RTCAlarm_Handler\n\
  .word   _USBWakeUp_Handler\n\
  .word   _TIM8_BRK_Handler\n\
  .word   _TIM8_UP_Handler\n\
  .word   _TIM8_TRG_COM_Handler\n\
  .word   _TIM8_CC_Handler\n\
  .word   _RNG_Handler\n\
  .word   _FSMC_Handler\n\
  .word   _SDIO_Handler\n\
  .word   _TIM5_Handler\n\
  .word   _SPI3_Handler\n\
  .word   _UART4_Handler\n\
  .word   _UART5_Handler\n\
  .word   _TIM6_Handler\n\
  .word   _TIM7_Handler\n\
  .word   _DMA2_CH1_Handler\n\
  .word   _DMA2_CH2_Handler\n\
  .word   _DMA2_CH3_Handler\n\
  .word   _DMA2_CH4_Handler\n\
  .word   _DMA2_CH5_Handler\n\
  .word   _ETH_Handler\n\
  .word   _ETH_WKUP_Handler\n\
  .word   _CAN2_TX_Handler\n\
  .word   _CAN2_RX0_Handler\n\
  .word   _CAN2_RX1_Handler\n\
  .word   _OTG_FS_Handler\n\
  .word   _USBHSWakeUp_Handler\n\
  .word   _USBHS_Handler\n\
  .word   _DVP_Handler\n\
  .word   _UART6_Handler\n\
  .word   _UART7_Handler\n\
  .word   _UART8_Handler\n\
  .word   _TIM9_BRK_Handler\n\
  .word   _TIM9_UP_Handler\n\
  .word   _TIM9_TRG_COM_Handler\n\
  .word   _TIM9_CC_Handler\n\
  .word   _TIM10_BRK_Handler\n\
  .word   _TIM10_UP_Handler\n\
  .word   _TIM10_TRG_COM_Handler\n\
  .word   _TIM10_CC_Handler\n\
  .word   _DMA2_CH6_Handler\n\
  .word   _DMA2_CH7_Handler\n\
  .word   _DMA2_CH8_Handler\n\
  .word   _DMA2_CH9_Handler\n\
  .word   _DMA2_CH10_Handler\n\
  .word   _DMA2_CH11_Handler\n\
  .option   pop;\n\
	");
}

void handle_reset() {
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
