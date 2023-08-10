#ifndef __H_CH32V003
#define __H_CH32V003

enum RCC_SYSCLK_SRC {
  RCC_SYSCLK_SRC_HSI = 0,
  RCC_SYSCLK_SRC_HSE = 1,
  RCC_SYSCLK_SRC_PLL = 2,
};

enum GPIO_MODE {
  GPIO_MODE_INPUT = 0,
  GPIO_MODE_OUTPUT_10MHZ = 1,
  GPIO_MODE_OUTPUT_2MHZ = 2,
  GPIO_MODE_OUTPUT_50MHZ = 3,
};

enum GPIO_CNF_OUTPUT {
  GPIO_CNF_OUTPUT_PUSH_PULL = 0,
  GPIO_CNF_OUTPUT_OPEN_DRAIN = 1,
  GPIO_CNF_OUTPUT_FUNC_PUSH_PULL = 2,
  GPIO_CNF_OUTPUT_FUNC_OPEN_DRAIN = 3,
};

enum GPIO_CNF_INPUT {
  GPIO_CNF_INPUT_ANALOG = 0,
  GPIO_CNF_INPUT_FLOATING = 1,
  GPIO_CNF_INPUT_PULL_UP_DOWN = 3,
};

#define ESIG_FLACAP R32(0x1FFFF7E0)

#define ESIG_UNIID1 R32(0x1FFFF7E8)

#define ESIG_UNIID2 R32(0x1FFFF7EC)

#define ESIG_UNIID3 R32(0x1FFFF7F0)

#define TIM2_CTLR1 R32(0x40000000)

#define TIM2_CTLR2 R32(0x40000004)

#define TIM2_SMCFGR R32(0x40000008)

#define TIM2_DMAINTENR R32(0x4000000C)

#define TIM2_INTFR R32(0x40000010)

#define TIM2_SWEVGR R32(0x40000014)

#define TIM2_CHCTLR1 R32(0x40000018)

#define TIM2_CHCTLR2 R32(0x4000001C)

#define TIM2_CCER R32(0x40000020)

#define TIM2_CNT R32(0x40000024)

#define TIM2_PSC R32(0x40000028)

#define TIM2_ATRLR R32(0x4000002C)

#define TIM2_CH1CVR R32(0x40000034)

#define TIM2_CH2CVR R32(0x40000038)

#define TIM2_CH3CVR R32(0x4000003C)

#define TIM2_CH4CVR R32(0x40000040)

#define TIM2_DMACFGR R32(0x40000048)

#define TIM2_DMAADR R32(0x4000004C)

#define WWDG_CTLR R32(0x40002C00)

#define WWDG_CFGR R32(0x40002C04)

#define WWDG_STATR R32(0x40002C08)

#define IWDG_CTLR R32(0x40003000)

#define IWDG_PSCR R32(0x40003004)

#define IWDG_RLDR R32(0x40003008)

#define IWDG_STATR R32(0x4000300C)

#define I2C_CTLR1 R32(0x40005400)

#define I2C_CTLR2 R32(0x40005404)

#define I2C_OADDR1 R32(0x40005408)

#define I2C_OADDR2 R32(0x4000540C)

#define I2C_DATAR R32(0x40005410)

#define I2C_STAR1 R32(0x40005414)

#define I2C_STAR2 R32(0x40005418)

#define I2C_CKCFGR R32(0x4000541C)

#define PWR_CTLR R32(0x40007000)

#define PWR_CSR R32(0x40007004)

#define PWR_AWUCSR R32(0x40007008)

#define PWR_AWUWR R32(0x4000700C)

#define PWR_AWUPSC R32(0x40007010)

#define AFIO_PCFR1 R32(0x40010004)
typedef struct AFIO_PCFR1_bits_s {
  uint32_t SPI1RM : 1;
  uint32_t I2C1RM : 1;
  uint32_t USART1_RM : 1;
  uint32_t _r0 : 3;
  uint32_t TIM1RM : 2;
  uint32_t TIM2RM : 2;
  uint32_t _r1 : 5;
  uint32_t PA12_RM : 1;
  uint32_t _r2 : 1;
  uint32_t ADC_ETRGINJ_R : 1;
  uint32_t ADC_ETRGREG_R : 1;
  uint32_t _r3 : 2;
  uint32_t USART1_RM1 : 1;
  uint32_t I2CREMAP1 : 1;
  uint32_t TIM1_IREMAP : 1;
  uint32_t _r4 : 8;
} AFIO_PCFR1_bits_t;
#define AFIO_PCFR1_bits (*((volatile AFIO_PCFR1_bits_t *)&AFIO_PCFR1))

#define AFIO_EXTICR R32(0x40010008)
typedef struct AFIO_EXTICR_bits_s {
  uint32_t EXTI0 : 1;
  uint32_t EXTI1 : 1;
  uint32_t EXTI2 : 1;
  uint32_t EXTI3 : 1;
  uint32_t EXTI4 : 1;
  uint32_t EXTI5 : 1;
  uint32_t EXTI6 : 1;
  uint32_t EXTI7 : 1;
  uint32_t _r0 : 24;
} AFIO_EXTICR_bits_t;
#define AFIO_EXTICR_bits (*((volatile AFIO_EXTICR_bits_t *)&AFIO_EXTICR))

#define EXTI_INTENR R32(0x40010400)

#define EXTI_EVENR R32(0x40010404)

#define EXTI_RTENR R32(0x40010408)

#define EXTI_FTENR R32(0x4001040C)

#define EXTI_SWIEVR R32(0x40010410)

#define EXTI_INTFR R32(0x40010414)

#define GPIOA_CFGLR R32(0x40010800)
typedef struct GPIOx_CFGLR_bits_s {
  uint32_t MODE0 : 2;
  uint32_t CNF0 : 2;
  uint32_t MODE1 : 2;
  uint32_t CNF1 : 2;
  uint32_t MODE2 : 2;
  uint32_t CNF2 : 2;
  uint32_t MODE3 : 2;
  uint32_t CNF3 : 2;
  uint32_t MODE4 : 2;
  uint32_t CNF4 : 2;
  uint32_t MODE5 : 2;
  uint32_t CNF5 : 2;
  uint32_t MODE6 : 2;
  uint32_t CNF6 : 2;
  uint32_t MODE7 : 2;
  uint32_t CNF7 : 2;
} GPIOx_CFGLR_bits_t;
#define GPIOA_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOA_CFGLR))

#define GPIOA_INDR R32(0x40010808)
typedef struct GPIOx_INDR_bits_s {
  uint32_t IDR0 : 1;
  uint32_t IDR1 : 1;
  uint32_t IDR2 : 1;
  uint32_t IDR3 : 1;
  uint32_t IDR4 : 1;
  uint32_t IDR5 : 1;
  uint32_t IDR6 : 1;
  uint32_t IDR7 : 1;
  uint32_t _r0 : 24;
} GPIOx_INDR_bits_t;
#define GPIOA_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOA_INDR))

#define GPIOA_OUTDR R32(0x4001080C)
typedef struct GPIOx_OUTDR_bits_s {
  uint32_t ODR0 : 1;
  uint32_t ODR1 : 1;
  uint32_t ODR2 : 1;
  uint32_t ODR3 : 1;
  uint32_t ODR4 : 1;
  uint32_t ODR5 : 1;
  uint32_t ODR6 : 1;
  uint32_t ODR7 : 1;
  uint32_t _r0 : 24;
} GPIOx_OUTDR_bits_t;
#define GPIOA_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOA_OUTDR))

#define GPIOA_BSHR R32(0x40010810)
typedef struct GPIOx_BSHR_bits_s {
  uint32_t BS0 : 1;
  uint32_t BS1 : 1;
  uint32_t BS2 : 1;
  uint32_t BS3 : 1;
  uint32_t BS4 : 1;
  uint32_t BS5 : 1;
  uint32_t BS6 : 1;
  uint32_t BS7 : 1;
  uint32_t _r0 : 8;
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t _r1 : 8;
} GPIOx_BSHR_bits_t;
#define GPIOA_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOA_BSHR))

#define GPIOA_BCR R32(0x40010814)

#define GPIOA_LCKR R32(0x40010818)
typedef struct GPIOx_LCKR_bits_s {
  uint32_t LCK0 : 1;
  uint32_t LCK1 : 1;
  uint32_t LCK2 : 1;
  uint32_t LCK3 : 1;
  uint32_t LCK4 : 1;
  uint32_t LCK5 : 1;
  uint32_t LCK6 : 1;
  uint32_t LCK7 : 1;
  uint32_t LCKK : 1;
  uint32_t _r0 : 23;
} GPIOx_LCKR_bits_t;
#define GPIOA_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOA_LCKR))

#define GPIOC_CFGLR R32(0x40011000)
#define GPIOC_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOC_CFGLR))

#define GPIOC_INDR R32(0x40011008)
#define GPIOC_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOC_INDR))

#define GPIOC_OUTDR R32(0x4001100C)
#define GPIOC_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOC_OUTDR))

#define GPIOC_BSHR R32(0x40011010)
#define GPIOC_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOC_BSHR))

#define GPIOC_BCR R32(0x40011014)

#define GPIOC_LCKR R32(0x40011018)
#define GPIOC_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOC_LCKR))

#define GPIOD_CFGLR R32(0x40011400)
#define GPIOD_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOD_CFGLR))

#define GPIOD_INDR R32(0x40011408)
#define GPIOD_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOD_INDR))

#define GPIOD_OUTDR R32(0x4001140C)
#define GPIOD_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOD_OUTDR))

#define GPIOD_BSHR R32(0x40011410)
#define GPIOD_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOD_BSHR))

#define GPIOD_BCR R32(0x40011414)

#define GPIOD_LCKR R32(0x40011418)
#define GPIOD_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOD_LCKR))

#define ADC_STATR R32(0x40012400)

#define ADC_CTLR1 R32(0x40012404)

#define ADC_CTLR2 R32(0x40012408)

#define ADC_SAMPTR1 R32(0x4001240C)

#define ADC_SAMPTR2 R32(0x40012410)

#define ADC_IOFR1 R32(0x40012414)

#define ADC_IOFR2 R32(0x40012418)

#define ADC_IOFR3 R32(0x4001241C)

#define ADC_IOFR4 R32(0x40012420)

#define ADC_WDHTR R32(0x40012424)

#define ADC_WDLTR R32(0x40012428)

#define ADC_RSQR1 R32(0x4001242C)

#define ADC_RSQR2 R32(0x40012430)

#define ADC_RSQR3 R32(0x40012434)

#define ADC_ISQR R32(0x40012438)

#define ADC_IDATAR1 R32(0x4001243C)

#define ADC_IDATAR2 R32(0x40012440)

#define ADC_IDATAR3 R32(0x40012444)

#define ADC_IDATAR4 R32(0x40012448)

#define ADC_RDATAR R32(0x4001244C)

#define ADC_DLYR R32(0x40012450)

#define TIM1_CTLR1 R32(0x40012C00)

#define TIM1_CTLR2 R32(0x40012C04)

#define TIM1_SMCFGR R32(0x40012C08)

#define TIM1_DMAINTENR R32(0x40012C0C)

#define TIM1_INTFR R32(0x40012C10)

#define TIM1_SWEVGR R32(0x40012C14)

#define TIM1_CHCTLR1 R32(0x40012C18)

#define TIM1_CHCTLR2 R32(0x40012C1C)

#define TIM1_CCER R32(0x40012C20)

#define TIM1_CNT R32(0x40012C24)

#define TIM1_PSC R32(0x40012C28)

#define TIM1_ATRLR R32(0x40012C2C)

#define TIM1_RPTCR R32(0x40012C30)

#define TIM1_CH1CVR R32(0x40012C34)

#define TIM1_CH2CVR R32(0x40012C38)

#define TIM1_CH3CVR R32(0x40012C3C)

#define TIM1_CH4CVR R32(0x40012C40)

#define TIM1_BDTR R32(0x40012C44)

#define TIM1_DMACFGR R32(0x40012C48)

#define TIM1_DMAADR R32(0x40012C4C)

#define SPI_CTLR1 R32(0x40013000)

#define SPI_CTLR2 R32(0x40013004)

#define SPI_STATR R32(0x40013008)

#define SPI_DATAR R32(0x4001300C)

#define SPI_CRCR R32(0x40013010)

#define SPI_RCRCR R32(0x40013014)

#define SPI_TCRCR R32(0x40013018)

#define SPI_HSCR R32(0x40013024)

#define USART_STATR R32(0x40013800)
typedef struct USART_STATR_bits_s {
  uint16_t PE : 1;
  uint16_t FE : 1;
  uint16_t NE : 1;
  uint16_t ORE : 1;
  uint16_t IDLE : 1;
  uint16_t RXNE : 1;
  uint16_t TC : 1;
  uint16_t TXE : 1;
  uint16_t LBD : 1;
  uint16_t CTS : 1;
  uint16_t _r0 : 6;
} USART_STATR_bits_t;
#define USART_STATR_bits (*((volatile USART_STATR_bits_t *)&USART_STATR))

#define USART_DATAR R32(0x40013804)
typedef struct USART_DATAR_bits_s {
  uint16_t DR : 9;
  uint16_t _r0 : 7;
} USART_DATAR_bits_t;
#define USART_DATAR_bits (*((volatile USART_DATAR_bits_t *)&USART_DATAR))

#define USART_BRR R32(0x40013808)
typedef struct USART_BRR_bits_s {
  uint16_t DIV_Fraction : 4;
  uint16_t DIV_Mantissa : 12;
} USART_BRR_bits_t;
#define USART_BRR_bits (*((volatile USART_BRR_bits_t *)&USART_BRR))

#define USART_CTLR1 R32(0x4001380c)
typedef struct USART_CTLR1_bits_s {
  uint16_t SBK : 1;
  uint16_t RWU : 1;
  uint16_t RE : 1;
  uint16_t TE : 1;
  uint16_t IDLEIE : 1;
  uint16_t RXNEIE : 1;
  uint16_t TCIE : 1;
  uint16_t TXEIE : 1;
  uint16_t PEIE : 1;
  uint16_t PS : 1;
  uint16_t PCE : 1;
  uint16_t WAKE : 1;
  uint16_t M : 1;
  uint16_t UE : 1;
  uint16_t _r0 : 2;
} USART_CTLR1_bits_t;
#define USART_CTLR1_bits (*((volatile USART_CTLR1_bits_t *)&USART_CTLR1))

#define USART_CTLR2 R32(0x40013810)
typedef struct USART_CTLR2_bits_s {
  uint16_t ADD : 4;
  uint16_t _r0 : 1;
  uint16_t LBDL : 1;
  uint16_t LBDIE : 1;
  uint16_t _r1 : 1;
  uint16_t LBCL : 1;
  uint16_t CPHA : 1;
  uint16_t CPOL : 1;
  uint16_t CLKEN : 1;
  uint16_t STOP : 2;
  uint16_t LINEN : 1;
} USART_CTLR2_bits_t;
#define USART_CTLR2_bits (*((volatile USART_CTLR2_bits_t *)&USART_CTLR2))

#define USART_CTLR3 R32(0x40013814)
typedef struct USART_CTLR3_bits_s {
  uint16_t EIE : 1;
  uint16_t IREN : 1;
  uint16_t IRLP : 1;
  uint16_t HDSEL : 1;
  uint16_t NACK : 1;
  uint16_t SCEN : 1;
  uint16_t DMAR : 1;
  uint16_t DMAT : 1;
  uint16_t RTSE : 1;
  uint16_t CTSE : 1;
  uint16_t CTSIE : 1;
  uint16_t _r0 : 5;
} USART_CTLR3_bits_t;
#define USART_CTLR3_bits (*((volatile USART_CTLR3_bits_t *)&USART_CTLR3))

#define USART_GPR R32(0x40013818)
typedef struct USART_GPR_bits_s {
  uint16_t PSC : 8;
  uint16_t GT : 8;
} USART_GPR_bits_t;
#define USART_GPR_bits (*((volatile USART_GPR_bits_t *)&USART_GPR))

#define DMA_INTFR R32(0x40020000)

#define DMA_INTFCR R32(0x40020004)

#define DMA_CFGR1 R32(0x40020008)

#define DMA_CNTR1 R32(0x4002000C)

#define DMA_PADDR1 R32(0x40020010)

#define DMA_MADDR1 R32(0x40020014)

#define DMA_CFGR2 R32(0x4002001C)

#define DMA_CNTR2 R32(0x40020020)

#define DMA_PADDR2 R32(0x40020024)

#define DMA_MADDR2 R32(0x40020028)

#define DMA_CFGR3 R32(0x40020030)

#define DMA_CNTR3 R32(0x40020034)

#define DMA_PADDR3 R32(0x40020038)

#define DMA_MADDR3 R32(0x4002003C)

#define DMA_CFGR4 R32(0x40020044)

#define DMA_CNTR4 R32(0x40020048)

#define DMA_PADDR4 R32(0x4002004C)

#define DMA_MADDR4 R32(0x40020050)

#define DMA_CFGR5 R32(0x40020058)

#define DMA_CNTR5 R32(0x4002005C)

#define DMA_PADDR5 R32(0x40020060)

#define DMA_MADDR5 R32(0x40020064)

#define DMA_CFGR6 R32(0x4002006C)

#define DMA_CNTR6 R32(0x40020070)

#define DMA_PADDR6 R32(0x40020074)

#define DMA_MADDR6 R32(0x40020078)

#define DMA_CFGR7 R32(0x40020080)

#define DMA_CNTR7 R32(0x40020084)

#define DMA_PADDR7 R32(0x40020088)

#define DMA_MADDR7 R32(0x4002008C)

#define RCC_CTLR R32(0x40021000)
typedef struct RCC_CTLR_bits_s {
  uint32_t HSION : 1;
  uint32_t HSIRDY : 1;
  uint32_t _r0 : 1;
  uint32_t HSITRIM : 5;
  uint32_t HSICAL : 8;
  uint32_t HSEON : 1;
  uint32_t HSERDY : 1;
  uint32_t HSEBYP : 1;
  uint32_t CSSON : 1;
  uint32_t _r1 : 4;
  uint32_t PLLON : 1;
  uint32_t PLLRDY : 1;
  uint32_t _r2 : 6;
} RCC_CTLR_bits_t;
#define RCC_CTLR_bits (*((volatile RCC_CTLR_bits_t *)&RCC_CTLR))

#define RCC_CFGR0 R32(0x40021004)
typedef struct RCC_CFGR0_bits_s {
  uint32_t SW : 2;
  uint32_t SWS : 2;
  uint32_t HPRE : 4;
  uint32_t _r0 : 3;
  uint32_t ADCPRE : 5;
  uint32_t PLLSRC : 1;
  uint32_t _r1 : 7;
  uint32_t MCO : 3;
  uint32_t _r2 : 5;
} RCC_CFGR0_bits_t;
#define RCC_CFGR0_bits (*((volatile RCC_CFGR0_bits_t *)&RCC_CFGR0))

#define RCC_INTR R32(0x40021008)
typedef struct RCC_INTR_bits_s {
  uint32_t LSIRDYF : 1;
  uint32_t _r0 : 1;
  uint32_t HSIRDYF : 1;
  uint32_t HSERDYF : 1;
  uint32_t PLLRDYF : 1;
  uint32_t _r1 : 2;
  uint32_t CSSF : 1;
  uint32_t LSIRDYIE : 1;
  uint32_t _r2 : 1;
  uint32_t HSIRDYIE : 1;
  uint32_t HSERDYIE : 1;
  uint32_t PLLRDYIE : 1;
  uint32_t _r3 : 3;
  uint32_t LSIRDYC : 1;
  uint32_t _r4 : 2;
  uint32_t HSERDYC : 1;
  uint32_t HSIRDYC : 1;
  uint32_t PLLRDYC : 1;
  uint32_t _r5 : 1;
  uint32_t CSSC : 1;
  uint32_t _r6 : 8;
} RCC_INTR_bits_t;
#define RCC_INTR_bits (*((volatile RCC_INTR_bits_t *)&RCC_INTR))

#define RCC_APB2PRSTR R32(0x4002100C)
typedef struct RCC_APB2PRSTR_bits_s {
  uint32_t AFIORST : 1;
  uint32_t _r0 : 1;
  uint32_t IOPARST : 1;
  uint32_t _r1 : 1;
  uint32_t IOPCRST : 1;
  uint32_t IOPDRST : 1;
  uint32_t _r2 : 3;
  uint32_t ADC1RST : 1;
  uint32_t _r3 : 1;
  uint32_t TIM1RST : 1;
  uint32_t SPI1RST : 1;
  uint32_t _r4 : 1;
  uint32_t USART1RST : 1;
  uint32_t _r5 : 17;
} RCC_APB2PRSTR_bits_t;
#define RCC_APB2PRSTR_bits (*((volatile RCC_APB2PRSTR_bits_t *)&RCC_APB2PRSTR))

#define RCC_APB1PRSTR R32(0x40021010)
typedef struct RCC_APB1PRSTR_bits_s {
  uint32_t TIM2RST : 1;
  uint32_t _r0 : 10;
  uint32_t WWDGRST : 1;
  uint32_t _r1 : 9;
  uint32_t I2C1RST : 1;
  uint32_t _r2 : 6;
  uint32_t PWRRST : 1;
  uint32_t _r3 : 3;
} RCC_APB1PRSTR_bits_t;
#define RCC_APB1PRSTR_bits (*((volatile RCC_APB1PRSTR_bits_t *)&RCC_APB1PRSTR))

#define RCC_AHBPCENR R32(0x40021014)
typedef struct RCC_AHBPCENR_bits_s {
  uint32_t DMA1EN : 1;
  uint32_t _r0 : 1;
  uint32_t SRAMEN : 1;
  uint32_t _r1 : 29;
} RCC_AHBPCENR_bits_t;
#define RCC_AHBPCENR_bits (*((volatile RCC_AHBPCENR_bits_t *)&RCC_AHBPCENR))

#define RCC_APB2PCENR R32(0x40021018)
typedef struct RCC_APB2PCENR_bits_s {
  uint32_t AFIOEN : 1;
  uint32_t _r0 : 1;
  uint32_t IOPAEN : 1;
  uint32_t _r1 : 1;
  uint32_t IOPCEN : 1;
  uint32_t IOPDEN : 1;
  uint32_t _r2 : 3;
  uint32_t ADC1EN : 1;
  uint32_t _r3 : 1;
  uint32_t TIM1EN : 1;
  uint32_t SPI1EN : 1;
  uint32_t _r4 : 1;
  uint32_t USART1EN : 1;
  uint32_t _r5 : 17;
} RCC_APB2PCENR_bits_t;
#define RCC_APB2PCENR_bits (*((volatile RCC_APB2PCENR_bits_t *)&RCC_APB2PCENR))

#define RCC_APB1PCENR R32(0x4002101C)
typedef struct RCC_APB1PCENR_bits_s {
  uint32_t TIM2EN : 1;
  uint32_t _r0 : 10;
  uint32_t WWDGEN : 1;
  uint32_t _r1 : 9;
  uint32_t I2C1EN : 1;
  uint32_t _r2 : 6;
  uint32_t PWREN : 1;
  uint32_t _r3 : 3;
} RCC_APB1PCENR_bits_t;
#define RCC_APB1PCENR_bits (*((volatile RCC_APB1PCENR_bits_t *)&RCC_APB1PCENR))

#define RCC_RSTSCKR R32(0x40021024)
typedef struct RCC_RSTSCKR_bits_s {
  uint32_t LSION : 1;
  uint32_t LSIRDY : 1;
  uint32_t _r0 : 22;
  uint32_t RMVF : 1;
  uint32_t _r1 : 1;
  uint32_t PINRSTF : 1;
  uint32_t PORRSTF : 1;
  uint32_t SFTRSTF : 1;
  uint32_t IWDGRSTF : 1;
  uint32_t WWDGRSTF : 1;
  uint32_t LPWRRSTF : 1;
} RCC_RSTSCKR_bits_t;
#define RCC_RSTSCKR_bits (*((volatile RCC_RSTSCKR_bits_t *)&RCC_RSTSCKR))

#define FLASH_ACTLR R32(0x40022000)

#define FLASH_KEYR R32(0x40022004)

#define FLASH_OBKEYR R32(0x40022008)

#define FLASH_STATR R32(0x4002200C)

#define FLASH_CTLR R32(0x40022010)

#define FLASH_ADDR R32(0x40022014)

#define FLASH_OBR R32(0x4002201C)

#define FLASH_WPR R32(0x40022020)

#define FLASH_MODEKEYR R32(0x40022024)

#define FLASH_BOOT_MODEKEYR R32(0x40022028)

#define EXTEN_CTR R32(0x40023800)

#define PFIC_ISR1 R32(0xE000E000)

#define PFIC_ISR2 R32(0xE000E004)

#define PFIC_IPR1 R32(0xE000E020)

#define PFIC_IPR2 R32(0xE000E024)

#define PFIC_ITHRESDR R32(0xE000E040)

#define PFIC_CFGR R32(0xE000E048)

#define STK_CTLR R32(0xE000F000)
typedef struct STK_CTLR_bits_s {
  uint32_t STE : 1;
  uint32_t STIE : 1;
  uint32_t STCLK : 1;
  uint32_t STRE : 1;
  uint32_t _r0 : 27;
  uint32_t SWIE : 1;
} STK_CTLR_bits_t;
#define STK_CTLR_bits (*((volatile STK_CTLR_bits_t *)&STK_CTLR))

#define STK_SR R32(0xE000F004)
typedef struct STK_SR_bits_s {
  uint32_t CNTIF : 1;
  uint32_t _r0 : 31;
} STK_SR_bits_t;
#define STK_SR_bits (*((volatile STK_SR_bits_t *)&STK_SR))

#define STK_CNTL R32(0xE000F008)
typedef struct STK_CNTL_bits_s {
  uint32_t CNT : 32;
} STK_CNTL_bits_t;
#define STK_CNTL_bits (*((volatile STK_CNTL_bits_t *)&STK_CNTL))

#define STK_CMPLR R32(0xE000F010)
typedef struct STK_CMPLR_bits_s {
  uint32_t CMP : 32;
} STK_CMPLR_bits_t;
#define STK_CMPLR_bits (*((volatile STK_CMPLR_bits_t *)&STK_CMPLR))
#endif // __H_CH32V003
