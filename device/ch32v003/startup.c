#ifdef CPLUSPLUS
// Method to call the C++ constructors
void __libc_init_array(void);
#endif

int main() __attribute__((used));

// If you don't override a specific handler, it will just spin forever.
void DefaultIRQHandler(void) __attribute__((section(".text.vector_handler")));

// This makes it so that all of the interrupt handlers just alias to
// DefaultIRQHandler unless they are individually overridden.
void NMI_Handler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void HardFault_Handler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void SysTick_Handler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void SW_Handler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void WWDG_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void PVD_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void FLASH_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void RCC_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void EXTI7_0_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void AWU_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel1_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel2_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel3_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel4_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel5_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel6_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void DMA1_Channel7_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void ADC1_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void I2C1_EV_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void I2C1_ER_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void USART1_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void SPI1_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void TIM1_BRK_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void TIM1_UP_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void TIM1_TRG_COM_IRQHandler(void)
    __attribute__((section(".text.vector_handler")))
    __attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void TIM1_CC_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));
void TIM2_IRQHandler(void) __attribute__((section(".text.vector_handler")))
__attribute((weak, alias("DefaultIRQHandler"))) __attribute__((used));

void IVT() __attribute__((naked)) __attribute((section(".init")))
__attribute((weak, alias("DefaultIVT")));
void DefaultIVT() __attribute__((naked)) __attribute((section(".init")));

void DefaultIRQHandler(void) {
  // Infinite Loop
  asm volatile("1: j 1b");
}

void DefaultIVT() {
  asm volatile("\n\
	.align  2\n\
	.option   push;\n\
	.option   norvc;\n\
	j handle_reset\n");
#if !defined(FUNCONF_TINYVECTOR) || !FUNCONF_TINYVECTOR
  asm volatile("\n\
	.word   0\n\
	.word   NMI_Handler               /* NMI Handler */                    \n\
	.word   HardFault_Handler         /* Hard Fault Handler */             \n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   0\n\
	.word   SysTick_Handler           /* SysTick Handler */                \n\
	.word   0\n\
	.word   SW_Handler                /* SW Handler */                     \n\
	.word   0\n\
	/* External Interrupts */                                              \n\
	.word   WWDG_IRQHandler           /* Window Watchdog */                \n\
	.word   PVD_IRQHandler            /* PVD through EXTI Line detect */   \n\
	.word   FLASH_IRQHandler          /* Flash */                          \n\
	.word   RCC_IRQHandler            /* RCC */                            \n\
	.word   EXTI7_0_IRQHandler        /* EXTI Line 7..0 */                 \n\
	.word   AWU_IRQHandler            /* AWU */                            \n\
	.word   DMA1_Channel1_IRQHandler  /* DMA1 Channel 1 */                 \n\
	.word   DMA1_Channel2_IRQHandler  /* DMA1 Channel 2 */                 \n\
	.word   DMA1_Channel3_IRQHandler  /* DMA1 Channel 3 */                 \n\
	.word   DMA1_Channel4_IRQHandler  /* DMA1 Channel 4 */                 \n\
	.word   DMA1_Channel5_IRQHandler  /* DMA1 Channel 5 */                 \n\
	.word   DMA1_Channel6_IRQHandler  /* DMA1 Channel 6 */                 \n\
	.word   DMA1_Channel7_IRQHandler  /* DMA1 Channel 7 */                 \n\
	.word   ADC1_IRQHandler           /* ADC1 */                           \n\
	.word   I2C1_EV_IRQHandler        /* I2C1 Event */                     \n\
	.word   I2C1_ER_IRQHandler        /* I2C1 Error */                     \n\
	.word   USART1_IRQHandler         /* USART1 */                         \n\
	.word   SPI1_IRQHandler           /* SPI1 */                           \n\
	.word   TIM1_BRK_IRQHandler       /* TIM1 Break */                     \n\
	.word   TIM1_UP_IRQHandler        /* TIM1 Update */                    \n\
	.word   TIM1_TRG_COM_IRQHandler   /* TIM1 Trigger and Commutation */   \n\
	.word   TIM1_CC_IRQHandler        /* TIM1 Capture Compare */           \n\
	.word   TIM2_IRQHandler           /* TIM2 */                           \n\
");
#endif
  asm volatile(".option   pop;\n");
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
