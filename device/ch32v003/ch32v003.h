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

enum GPIO_BANK {
  GPIO_BANK_A = 0,
  GPIO_BANK_C = 1,
  GPIO_BANK_D = 2,
};

enum INTERRUPT {
  INTERRUPT_NMI = 2,
  INTERRUPT_HardFault = 3,
  INTERRUPT_SysTick = 12,
  INTERRUPT_SW = 14,
  INTERRUPT_WWDG = 16,
  INTERRUPT_PVD = 17,
  INTERRUPT_FLASH = 18,
  INTERRUPT_RCC = 19,
  INTERRUPT_EXTI7_0 = 20,
  INTERRUPT_AWU = 21,
  INTERRUPT_DMA_CH1 = 22,
  INTERRUPT_DMA_CH2 = 23,
  INTERRUPT_DMA_CH3 = 24,
  INTERRUPT_DMA_CH4 = 25,
  INTERRUPT_DMA_CH5 = 26,
  INTERRUPT_DMA_CH6 = 27,
  INTERRUPT_DMA_CH7 = 28,
  INTERRUPT_ADC = 29,
  INTERRUPT_I2C1_EV = 30,
  INTERRUPT_I2C1_ER = 31,
  INTERRUPT_USART1 = 32,
  INTERRUPT_SPI1 = 33,
  INTERRUPT_TIM1BRK = 34,
  INTERRUPT_TIM1UP = 35,
  INTERRUPT_TIM1TRG = 36,
  INTERRUPT_TIM1CC = 37,
  INTERRUPT_TIM2 = 38,
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
typedef struct GPIOx_BCR_bits_s {
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t _r0 : 24;
} GPIOx_BCR_bits_t;
#define GPIOA_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOA_BCR))

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
#define GPIOC_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOC_BCR))

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
#define GPIOD_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOD_BCR))

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
typedef struct SPI_CTLR1_bits_s {
  uint16_t CPHA : 1;
  uint16_t CPOL : 1;
  uint16_t MSTR : 1;
  uint16_t BR : 3;
  uint16_t SPE : 1;
  uint16_t Reserved : 1;
  uint16_t SSI : 1;
  uint16_t SSM : 1;
  uint16_t RXONLY : 1;
  uint16_t DFF : 1;
  uint16_t CRCNEXT : 1;
  uint16_t CRCEN : 1;
  uint16_t BIDIOE : 1;
  uint16_t BIDIMODE : 1;
} SPI_CTLR1_bits_t;
#define SPI_CTLR1_bits (*((volatile SPI_CTLR1_bits_t *)&SPI_CTLR1))

#define SPI_CTLR2 R32(0x40013004)

#define SPI_STATR R32(0x40013008)
typedef struct SPI_STATR_bits_s {
  uint16_t RXNE : 1;
  uint16_t TXE : 1;
  uint16_t CHSIDE : 1;
  uint16_t UDR : 1;
  uint16_t CRCERR : 1;
  uint16_t MODF : 1;
  uint16_t OVR : 1;
  uint16_t BSY : 1;
  uint16_t _r0 : 8;
} SPI_STATR_bits_t;
#define SPI_STATR_bits (*((volatile SPI_STATR_bits_t *)&SPI_STATR))

#define SPI_DATAR R32(0x4001300C)
typedef struct SPI_DATAR_bits_s {
  uint16_t DR : 16;
} SPI_DATAR_bits_t;
#define SPI_DATAR_bits (*((volatile SPI_DATAR_bits_t *)&SPI_DATAR))

#define SPI_CRCR R32(0x40013010)
typedef struct SPI_CRCR_bits_s {
  uint16_t CRCPOLY : 8;
  uint16_t _r0 : 8;
} SPI_CRCR_bits_t;
#define SPI_CRCR_bits (*((volatile SPI_CRCR_bits_t *)&SPI_CRCR))

#define SPI_RCRCR R32(0x40013014)
typedef struct SPI_RCRCR_bits_s {
  uint16_t RXCRC : 16;
} SPI_RCRCR_bits_t;
#define SPI_RCRCR_bits (*((volatile SPI_RCRCR_bits_t *)&SPI_RCRCR))

#define SPI_TCRCR R32(0x40013018)

#define SPI_HSCR R32(0x40013024)
typedef struct SPI_HSCR_bits_s {
  uint16_t HSRXEN : 1;
  uint16_t _r0 : 15;
} SPI_HSCR_bits_t;
#define SPI_HSCR_bits (*((volatile SPI_HSCR_bits_t *)&SPI_HSCR))

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
typedef struct PFIC_ISR1_bits_s {
  uint32_t _r0 : 2;
  uint32_t INTENSTA2 : 1;
  uint32_t INTENSTA3 : 1;
  uint32_t _r1 : 8;
  uint32_t INTENSTA12 : 1;
  uint32_t _r2 : 1;
  uint32_t INTENSTA14 : 1;
  uint32_t _r3 : 1;
  uint32_t INTENSTA16 : 1;
  uint32_t INTENSTA17 : 1;
  uint32_t INTENSTA18 : 1;
  uint32_t INTENSTA19 : 1;
  uint32_t INTENSTA20 : 1;
  uint32_t INTENSTA21 : 1;
  uint32_t INTENSTA22 : 1;
  uint32_t INTENSTA23 : 1;
  uint32_t INTENSTA24 : 1;
  uint32_t INTENSTA25 : 1;
  uint32_t INTENSTA26 : 1;
  uint32_t INTENSTA27 : 1;
  uint32_t INTENSTA28 : 1;
  uint32_t INTENSTA29 : 1;
  uint32_t INTENSTA30 : 1;
  uint32_t INTENSTA31 : 1;
} PFIC_ISR1_bits_t;
#define PFIC_ISR1_bits (*((volatile PFIC_ISR1_bits_t *)&PFIC_ISR1))

#define PFIC_ISR2 R32(0xE000E004)
typedef struct PFIC_ISR2_bits_s {
  uint32_t INTENSTA32 : 1;
  uint32_t INTENSTA33 : 1;
  uint32_t INTENSTA34 : 1;
  uint32_t INTENSTA35 : 1;
  uint32_t INTENSTA36 : 1;
  uint32_t INTENSTA37 : 1;
  uint32_t INTENSTA38 : 1;
  uint32_t _r0 : 25;
} PFIC_ISR2_bits_t;
#define PFIC_ISR2_bits (*((volatile PFIC_ISR2_bits_t *)&PFIC_ISR2))

#define PFIC_IPR1 R32(0xE000E020)
typedef struct PFIC_IPR1_bits_s {
  uint32_t _r0 : 2;
  uint32_t PENDSTA2 : 1;
  uint32_t PENDSTA3 : 1;
  uint32_t _r1 : 8;
  uint32_t PENDSTA12 : 1;
  uint32_t _r2 : 1;
  uint32_t PENDSTA14 : 1;
  uint32_t _r3 : 1;
  uint32_t PENDSTA16 : 1;
  uint32_t PENDSTA17 : 1;
  uint32_t PENDSTA18 : 1;
  uint32_t PENDSTA19 : 1;
  uint32_t PENDSTA20 : 1;
  uint32_t PENDSTA21 : 1;
  uint32_t PENDSTA22 : 1;
  uint32_t PENDSTA23 : 1;
  uint32_t PENDSTA24 : 1;
  uint32_t PENDSTA25 : 1;
  uint32_t PENDSTA26 : 1;
  uint32_t PENDSTA27 : 1;
  uint32_t PENDSTA28 : 1;
  uint32_t PENDSTA29 : 1;
  uint32_t PENDSTA30 : 1;
  uint32_t PENDSTA31 : 1;
} PFIC_IPR1_bits_t;
#define PFIC_IPR1_bits (*((volatile PFIC_IPR1_bits_t *)&PFIC_IPR1))

#define PFIC_IPR2 R32(0xE000E024)
typedef struct PFIC_IPR2_bits_s {
  uint32_t PENDSTA32 : 1;
  uint32_t PENDSTA33 : 1;
  uint32_t PENDSTA34 : 1;
  uint32_t PENDSTA35 : 1;
  uint32_t PENDSTA36 : 1;
  uint32_t PENDSTA37 : 1;
  uint32_t PENDSTA38 : 1;
  uint32_t _r0 : 25;
} PFIC_IPR2_bits_t;
#define PFIC_IPR2_bits (*((volatile PFIC_IPR2_bits_t *)&PFIC_IPR2))

#define PFIC_ITHRESDR R32(0xE000E040)
typedef struct PFIC_ITHRESDR_bits_s {
  uint32_t THRESHOLD : 8;
  uint32_t _r0 : 24;
} PFIC_ITHRESDR_bits_t;
#define PFIC_ITHRESDR_bits (*((volatile PFIC_ITHRESDR_bits_t *)&PFIC_ITHRESDR))

#define PFIC_CFGR R32(0xE000E048)
typedef struct PFIC_CFGR_bits_s {
  uint32_t _r0 : 7;
  uint32_t RESETSYS : 1;
  uint32_t _r1 : 8;
  uint32_t KEYCODE : 16;
} PFIC_CFGR_bits_t;
#define PFIC_CFGR_bits (*((volatile PFIC_CFGR_bits_t *)&PFIC_CFGR))

#define PFIC_GISR R32(0xE000E04C)
typedef struct PFIC_GISR_bits_s {
  uint32_t NESTSTA : 8;
  uint32_t GACTSTA : 1;
  uint32_t GPENDSTA : 1;
  uint32_t _r0 : 22;
} PFIC_GISR_bits_t;
#define PFIC_GISR_bits (*((volatile PFIC_GISR_bits_t *)&PFIC_GISR))

#define PFIC_VTFIDR R32(0xE000E050)
typedef struct PFIC_VTFIDR_bits_s {
  uint32_t VTFID0 : 8;
  uint32_t VTFID1 : 8;
  uint32_t _r0 : 16;
} PFIC_VTFIDR_bits_t;
#define PFIC_VTFIDR_bits (*((volatile PFIC_VTFIDR_bits_t *)&PFIC_VTFIDR))

#define PFIC_VTFADDRR0 R32(0xE000E060)
typedef struct PFIC_VTFADDRR0_bits_s {
  uint32_t VTF0EN : 1;
  uint32_t ADDR0 : 31;
} PFIC_VTFADDRR0_bits_t;
#define PFIC_VTFADDRR0_bits (*((volatile PFIC_VTFADDRR0_bits_t *)&PFIC_VTFADDRR0))

#define PFIC_VTFADDRR1 R32(0xE000E064)
typedef struct PFIC_VTFADDRR1_bits_s {
  uint32_t VTF1EN : 1;
  uint32_t ADDR1 : 31;
} PFIC_VTFADDRR1_bits_t;
#define PFIC_VTFADDRR1_bits (*((volatile PFIC_VTFADDRR1_bits_t *)&PFIC_VTFADDRR1))

#define PFIC_IENR1 R32(0xE000E100)
typedef struct PFIC_IENR1_bits_s {
  uint32_t _r0 : 12;
  uint32_t INTEN12 : 1;
  uint32_t _r1 : 1;
  uint32_t INTEN14 : 1;
  uint32_t _r2 : 1;
  uint32_t INTEN16 : 1;
  uint32_t INTEN17 : 1;
  uint32_t INTEN18 : 1;
  uint32_t INTEN19 : 1;
  uint32_t INTEN20 : 1;
  uint32_t INTEN21 : 1;
  uint32_t INTEN22 : 1;
  uint32_t INTEN23 : 1;
  uint32_t INTEN24 : 1;
  uint32_t INTEN25 : 1;
  uint32_t INTEN26 : 1;
  uint32_t INTEN27 : 1;
  uint32_t INTEN28 : 1;
  uint32_t INTEN29 : 1;
  uint32_t INTEN30 : 1;
  uint32_t INTEN31 : 1;
} PFIC_IENR1_bits_t;
#define PFIC_IENR1_bits (*((volatile PFIC_IENR1_bits_t *)&PFIC_IENR1))

#define PFIC_IENR2 R32(0xE000E104)
typedef struct PFIC_IENR2_bits_s {
  uint32_t INTEN32 : 1;
  uint32_t INTEN33 : 1;
  uint32_t INTEN34 : 1;
  uint32_t INTEN35 : 1;
  uint32_t INTEN36 : 1;
  uint32_t INTEN37 : 1;
  uint32_t INTEN38 : 1;
  uint32_t _r0 : 25;
} PFIC_IENR2_bits_t;
#define PFIC_IENR2_bits (*((volatile PFIC_IENR2_bits_t *)&PFIC_IENR2))

#define PFIC_IRER1 R32(0xE000E180)
typedef struct PFIC_IRER1_bits_s {
  uint32_t _r0 : 12;
  uint32_t INTRSET12 : 1;
  uint32_t _r1 : 1;
  uint32_t INTRSET14 : 1;
  uint32_t _r2 : 1;
  uint32_t INTRSET16 : 1;
  uint32_t INTRSET17 : 1;
  uint32_t INTRSET18 : 1;
  uint32_t INTRSET19 : 1;
  uint32_t INTRSET20 : 1;
  uint32_t INTRSET21 : 1;
  uint32_t INTRSET22 : 1;
  uint32_t INTRSET23 : 1;
  uint32_t INTRSET24 : 1;
  uint32_t INTRSET25 : 1;
  uint32_t INTRSET26 : 1;
  uint32_t INTRSET27 : 1;
  uint32_t INTRSET28 : 1;
  uint32_t INTRSET29 : 1;
  uint32_t INTRSET30 : 1;
  uint32_t INTRSET31 : 1;
} PFIC_IRER1_bits_t;
#define PFIC_IRER1_bits (*((volatile PFIC_IRER1_bits_t *)&PFIC_IRER1))

#define PFIC_IRER2 R32(0xE000E184)
typedef struct PFIC_IRER2_bits_s {
  uint32_t INTRSET32 : 1;
  uint32_t INTRSET33 : 1;
  uint32_t INTRSET34 : 1;
  uint32_t INTRSET35 : 1;
  uint32_t INTRSET36 : 1;
  uint32_t INTRSET37 : 1;
  uint32_t INTRSET38 : 1;
  uint32_t _r0 : 25;
} PFIC_IRER2_bits_t;
#define PFIC_IRER2_bits (*((volatile PFIC_IRER2_bits_t *)&PFIC_IRER2))

#define PFIC_IPSR1 R32(0xE000E200)
typedef struct PFIC_IPSR1_bits_s {
  uint32_t _r0 : 2;
  uint32_t PENDSET2 : 1;
  uint32_t PENDSET3 : 1;
  uint32_t _r1 : 8;
  uint32_t PENDSET12 : 1;
  uint32_t _r2 : 1;
  uint32_t PENDSET14 : 1;
  uint32_t _r3 : 1;
  uint32_t PENDSET16 : 1;
  uint32_t PENDSET17 : 1;
  uint32_t PENDSET18 : 1;
  uint32_t PENDSET19 : 1;
  uint32_t PENDSET20 : 1;
  uint32_t PENDSET21 : 1;
  uint32_t PENDSET22 : 1;
  uint32_t PENDSET23 : 1;
  uint32_t PENDSET24 : 1;
  uint32_t PENDSET25 : 1;
  uint32_t PENDSET26 : 1;
  uint32_t PENDSET27 : 1;
  uint32_t PENDSET28 : 1;
  uint32_t PENDSET29 : 1;
  uint32_t PENDSET30 : 1;
  uint32_t PENDSET31 : 1;
} PFIC_IPSR1_bits_t;
#define PFIC_IPSR1_bits (*((volatile PFIC_IPSR1_bits_t *)&PFIC_IPSR1))

#define PFIC_IPSR2 R32(0xE000E204)
typedef struct PFIC_IPSR2_bits_s {
  uint32_t PENDSET32 : 1;
  uint32_t PENDSET33 : 1;
  uint32_t PENDSET34 : 1;
  uint32_t PENDSET35 : 1;
  uint32_t PENDSET36 : 1;
  uint32_t PENDSET37 : 1;
  uint32_t PENDSET38 : 1;
  uint32_t _r0 : 25;
} PFIC_IPSR2_bits_t;
#define PFIC_IPSR2_bits (*((volatile PFIC_IPSR2_bits_t *)&PFIC_IPSR2))

#define PFIC_IPRR1 R32(0xE000E280)
typedef struct PFIC_IPRR1_bits_s {
  uint32_t _r0 : 2;
  uint32_t PENDRESET2 : 1;
  uint32_t PENDRESET3 : 1;
  uint32_t _r1 : 8;
  uint32_t PENDRESET12 : 1;
  uint32_t _r2 : 1;
  uint32_t PENDRESET14 : 1;
  uint32_t _r3 : 1;
  uint32_t PENDRESET16 : 1;
  uint32_t PENDRESET17 : 1;
  uint32_t PENDRESET18 : 1;
  uint32_t PENDRESET19 : 1;
  uint32_t PENDRESET20 : 1;
  uint32_t PENDRESET21 : 1;
  uint32_t PENDRESET22 : 1;
  uint32_t PENDRESET23 : 1;
  uint32_t PENDRESET24 : 1;
  uint32_t PENDRESET25 : 1;
  uint32_t PENDRESET26 : 1;
  uint32_t PENDRESET27 : 1;
  uint32_t PENDRESET28 : 1;
  uint32_t PENDRESET29 : 1;
  uint32_t PENDRESET30 : 1;
  uint32_t PENDRESET31 : 1;
} PFIC_IPRR1_bits_t;
#define PFIC_IPRR1_bits (*((volatile PFIC_IPRR1_bits_t *)&PFIC_IPRR1))

#define PFIC_IPRR2 R32(0xE000E284)
typedef struct PFIC_IPRR2_bits_s {
  uint32_t PENDRESET32 : 1;
  uint32_t PENDRESET33 : 1;
  uint32_t PENDRESET34 : 1;
  uint32_t PENDRESET35 : 1;
  uint32_t PENDRESET36 : 1;
  uint32_t PENDRESET37 : 1;
  uint32_t PENDRESET38 : 1;
  uint32_t _r0 : 25;
} PFIC_IPRR2_bits_t;
#define PFIC_IPRR2_bits (*((volatile PFIC_IPRR2_bits_t *)&PFIC_IPRR2))

#define PFIC_IACTR1 R32(0xE000E300)
typedef struct PFIC_IACTR1_bits_s {
  uint32_t _r0 : 2;
  uint32_t IACTS2 : 1;
  uint32_t IACTS3 : 1;
  uint32_t _r1 : 8;
  uint32_t IACTS12 : 1;
  uint32_t _r2 : 1;
  uint32_t IACTS14 : 1;
  uint32_t _r3 : 1;
  uint32_t IACTS16 : 1;
  uint32_t IACTS17 : 1;
  uint32_t IACTS18 : 1;
  uint32_t IACTS19 : 1;
  uint32_t IACTS20 : 1;
  uint32_t IACTS21 : 1;
  uint32_t IACTS22 : 1;
  uint32_t IACTS23 : 1;
  uint32_t IACTS24 : 1;
  uint32_t IACTS25 : 1;
  uint32_t IACTS26 : 1;
  uint32_t IACTS27 : 1;
  uint32_t IACTS28 : 1;
  uint32_t IACTS29 : 1;
  uint32_t IACTS30 : 1;
  uint32_t IACTS31 : 1;
} PFIC_IACTR1_bits_t;
#define PFIC_IACTR1_bits (*((volatile PFIC_IACTR1_bits_t *)&PFIC_IACTR1))

#define PFIC_IACTR2 R32(0xE000E304)
typedef struct PFIC_IACTR2_bits_s {
  uint32_t IACTS32 : 1;
  uint32_t IACTS33 : 1;
  uint32_t IACTS34 : 1;
  uint32_t IACTS35 : 1;
  uint32_t IACTS36 : 1;
  uint32_t IACTS37 : 1;
  uint32_t IACTS38 : 1;
  uint32_t _r0 : 25;
} PFIC_IACTR2_bits_t;
#define PFIC_IACTR2_bits (*((volatile PFIC_IACTR2_bits_t *)&PFIC_IACTR2))

#define PFIC_IPRIOR0 R32(0xE000E400)
typedef struct PFIC_IPRIOR0_bits_s {
  uint32_t IP_0 : 8;
  uint32_t IP_1 : 8;
  uint32_t IP_2 : 8;
  uint32_t IP_3 : 8;
} PFIC_IPRIOR0_bits_t;
#define PFIC_IPRIOR0_bits (*((volatile PFIC_IPRIOR0_bits_t *)&PFIC_IPRIOR0))

#define PFIC_IPRIOR1 R32(0xE000E404)
typedef struct PFIC_IPRIOR1_bits_s {
  uint32_t IP_4 : 8;
  uint32_t IP_5 : 8;
  uint32_t IP_6 : 8;
  uint32_t IP_7 : 8;
} PFIC_IPRIOR1_bits_t;
#define PFIC_IPRIOR1_bits (*((volatile PFIC_IPRIOR1_bits_t *)&PFIC_IPRIOR1))

#define PFIC_IPRIOR2 R32(0xE000E408)
typedef struct PFIC_IPRIOR2_bits_s {
  uint32_t IP_8 : 8;
  uint32_t IP_9 : 8;
  uint32_t IP_10 : 8;
  uint32_t IP_11 : 8;
} PFIC_IPRIOR2_bits_t;
#define PFIC_IPRIOR2_bits (*((volatile PFIC_IPRIOR2_bits_t *)&PFIC_IPRIOR2))

#define PFIC_IPRIOR3 R32(0xE000E40C)
typedef struct PFIC_IPRIOR3_bits_s {
  uint32_t IP_12 : 8;
  uint32_t IP_13 : 8;
  uint32_t IP_14 : 8;
  uint32_t IP_15 : 8;
} PFIC_IPRIOR3_bits_t;
#define PFIC_IPRIOR3_bits (*((volatile PFIC_IPRIOR3_bits_t *)&PFIC_IPRIOR3))

#define PFIC_IPRIOR4 R32(0xE000E410)
typedef struct PFIC_IPRIOR4_bits_s {
  uint32_t IP_16 : 8;
  uint32_t IP_17 : 8;
  uint32_t IP_18 : 8;
  uint32_t IP_19 : 8;
} PFIC_IPRIOR4_bits_t;
#define PFIC_IPRIOR4_bits (*((volatile PFIC_IPRIOR4_bits_t *)&PFIC_IPRIOR4))

#define PFIC_IPRIOR5 R32(0xE000E414)
typedef struct PFIC_IPRIOR5_bits_s {
  uint32_t IP_20 : 8;
  uint32_t IP_21 : 8;
  uint32_t IP_22 : 8;
  uint32_t IP_23 : 8;
} PFIC_IPRIOR5_bits_t;
#define PFIC_IPRIOR5_bits (*((volatile PFIC_IPRIOR5_bits_t *)&PFIC_IPRIOR5))

#define PFIC_IPRIOR6 R32(0xE000E418)
typedef struct PFIC_IPRIOR6_bits_s {
  uint32_t IP_24 : 8;
  uint32_t IP_25 : 8;
  uint32_t IP_26 : 8;
  uint32_t IP_27 : 8;
} PFIC_IPRIOR6_bits_t;
#define PFIC_IPRIOR6_bits (*((volatile PFIC_IPRIOR6_bits_t *)&PFIC_IPRIOR6))

#define PFIC_IPRIOR7 R32(0xE000E41C)
typedef struct PFIC_IPRIOR7_bits_s {
  uint32_t IP_28 : 8;
  uint32_t IP_29 : 8;
  uint32_t IP_30 : 8;
  uint32_t IP_31 : 8;
} PFIC_IPRIOR7_bits_t;
#define PFIC_IPRIOR7_bits (*((volatile PFIC_IPRIOR7_bits_t *)&PFIC_IPRIOR7))

#define PFIC_IPRIOR8 R32(0xE000E420)
typedef struct PFIC_IPRIOR8_bits_s {
  uint32_t IP_32 : 8;
  uint32_t IP_33 : 8;
  uint32_t IP_34 : 8;
  uint32_t IP_35 : 8;
} PFIC_IPRIOR8_bits_t;
#define PFIC_IPRIOR8_bits (*((volatile PFIC_IPRIOR8_bits_t *)&PFIC_IPRIOR8))

#define PFIC_IPRIOR9 R32(0xE000E424)
typedef struct PFIC_IPRIOR9_bits_s {
  uint32_t IP_36 : 8;
  uint32_t IP_37 : 8;
  uint32_t IP_38 : 8;
  uint32_t IP_39 : 8;
} PFIC_IPRIOR9_bits_t;
#define PFIC_IPRIOR9_bits (*((volatile PFIC_IPRIOR9_bits_t *)&PFIC_IPRIOR9))

#define PFIC_IPRIOR10 R32(0xE000E428)
typedef struct PFIC_IPRIOR10_bits_s {
  uint32_t IP_40 : 8;
  uint32_t IP_41 : 8;
  uint32_t IP_42 : 8;
  uint32_t IP_43 : 8;
} PFIC_IPRIOR10_bits_t;
#define PFIC_IPRIOR10_bits (*((volatile PFIC_IPRIOR10_bits_t *)&PFIC_IPRIOR10))

#define PFIC_IPRIOR11 R32(0xE000E42C)
typedef struct PFIC_IPRIOR11_bits_s {
  uint32_t IP_44 : 8;
  uint32_t IP_45 : 8;
  uint32_t IP_46 : 8;
  uint32_t IP_47 : 8;
} PFIC_IPRIOR11_bits_t;
#define PFIC_IPRIOR11_bits (*((volatile PFIC_IPRIOR11_bits_t *)&PFIC_IPRIOR11))

#define PFIC_IPRIOR12 R32(0xE000E430)
typedef struct PFIC_IPRIOR12_bits_s {
  uint32_t IP_48 : 8;
  uint32_t IP_49 : 8;
  uint32_t IP_50 : 8;
  uint32_t IP_51 : 8;
} PFIC_IPRIOR12_bits_t;
#define PFIC_IPRIOR12_bits (*((volatile PFIC_IPRIOR12_bits_t *)&PFIC_IPRIOR12))

#define PFIC_IPRIOR13 R32(0xE000E434)
typedef struct PFIC_IPRIOR13_bits_s {
  uint32_t IP_52 : 8;
  uint32_t IP_53 : 8;
  uint32_t IP_54 : 8;
  uint32_t IP_55 : 8;
} PFIC_IPRIOR13_bits_t;
#define PFIC_IPRIOR13_bits (*((volatile PFIC_IPRIOR13_bits_t *)&PFIC_IPRIOR13))

#define PFIC_IPRIOR14 R32(0xE000E438)
typedef struct PFIC_IPRIOR14_bits_s {
  uint32_t IP_56 : 8;
  uint32_t IP_57 : 8;
  uint32_t IP_58 : 8;
  uint32_t IP_59 : 8;
} PFIC_IPRIOR14_bits_t;
#define PFIC_IPRIOR14_bits (*((volatile PFIC_IPRIOR14_bits_t *)&PFIC_IPRIOR14))

#define PFIC_IPRIOR15 R32(0xE000E43C)
typedef struct PFIC_IPRIOR15_bits_s {
  uint32_t IP_60 : 8;
  uint32_t IP_61 : 8;
  uint32_t IP_62 : 8;
  uint32_t IP_63 : 8;
} PFIC_IPRIOR15_bits_t;
#define PFIC_IPRIOR15_bits (*((volatile PFIC_IPRIOR15_bits_t *)&PFIC_IPRIOR15))

#define PFIC_IPRIOR16 R32(0xE000E440)
typedef struct PFIC_IPRIOR16_bits_s {
  uint32_t IP_64 : 8;
  uint32_t IP_65 : 8;
  uint32_t IP_66 : 8;
  uint32_t IP_67 : 8;
} PFIC_IPRIOR16_bits_t;
#define PFIC_IPRIOR16_bits (*((volatile PFIC_IPRIOR16_bits_t *)&PFIC_IPRIOR16))

#define PFIC_IPRIOR17 R32(0xE000E444)
typedef struct PFIC_IPRIOR17_bits_s {
  uint32_t IP_68 : 8;
  uint32_t IP_69 : 8;
  uint32_t IP_70 : 8;
  uint32_t IP_71 : 8;
} PFIC_IPRIOR17_bits_t;
#define PFIC_IPRIOR17_bits (*((volatile PFIC_IPRIOR17_bits_t *)&PFIC_IPRIOR17))

#define PFIC_IPRIOR18 R32(0xE000E448)
typedef struct PFIC_IPRIOR18_bits_s {
  uint32_t IP_72 : 8;
  uint32_t IP_73 : 8;
  uint32_t IP_74 : 8;
  uint32_t IP_75 : 8;
} PFIC_IPRIOR18_bits_t;
#define PFIC_IPRIOR18_bits (*((volatile PFIC_IPRIOR18_bits_t *)&PFIC_IPRIOR18))

#define PFIC_IPRIOR19 R32(0xE000E44C)
typedef struct PFIC_IPRIOR19_bits_s {
  uint32_t IP_76 : 8;
  uint32_t IP_77 : 8;
  uint32_t IP_78 : 8;
  uint32_t IP_79 : 8;
} PFIC_IPRIOR19_bits_t;
#define PFIC_IPRIOR19_bits (*((volatile PFIC_IPRIOR19_bits_t *)&PFIC_IPRIOR19))

#define PFIC_IPRIOR20 R32(0xE000E450)
typedef struct PFIC_IPRIOR20_bits_s {
  uint32_t IP_80 : 8;
  uint32_t IP_81 : 8;
  uint32_t IP_82 : 8;
  uint32_t IP_83 : 8;
} PFIC_IPRIOR20_bits_t;
#define PFIC_IPRIOR20_bits (*((volatile PFIC_IPRIOR20_bits_t *)&PFIC_IPRIOR20))

#define PFIC_IPRIOR21 R32(0xE000E454)
typedef struct PFIC_IPRIOR21_bits_s {
  uint32_t IP_84 : 8;
  uint32_t IP_85 : 8;
  uint32_t IP_86 : 8;
  uint32_t IP_87 : 8;
} PFIC_IPRIOR21_bits_t;
#define PFIC_IPRIOR21_bits (*((volatile PFIC_IPRIOR21_bits_t *)&PFIC_IPRIOR21))

#define PFIC_IPRIOR22 R32(0xE000E458)
typedef struct PFIC_IPRIOR22_bits_s {
  uint32_t IP_88 : 8;
  uint32_t IP_89 : 8;
  uint32_t IP_90 : 8;
  uint32_t IP_91 : 8;
} PFIC_IPRIOR22_bits_t;
#define PFIC_IPRIOR22_bits (*((volatile PFIC_IPRIOR22_bits_t *)&PFIC_IPRIOR22))

#define PFIC_IPRIOR23 R32(0xE000E45C)
typedef struct PFIC_IPRIOR23_bits_s {
  uint32_t IP_92 : 8;
  uint32_t IP_93 : 8;
  uint32_t IP_94 : 8;
  uint32_t IP_95 : 8;
} PFIC_IPRIOR23_bits_t;
#define PFIC_IPRIOR23_bits (*((volatile PFIC_IPRIOR23_bits_t *)&PFIC_IPRIOR23))

#define PFIC_IPRIOR24 R32(0xE000E460)
typedef struct PFIC_IPRIOR24_bits_s {
  uint32_t IP_96 : 8;
  uint32_t IP_97 : 8;
  uint32_t IP_98 : 8;
  uint32_t IP_99 : 8;
} PFIC_IPRIOR24_bits_t;
#define PFIC_IPRIOR24_bits (*((volatile PFIC_IPRIOR24_bits_t *)&PFIC_IPRIOR24))

#define PFIC_IPRIOR25 R32(0xE000E464)
typedef struct PFIC_IPRIOR25_bits_s {
  uint32_t IP_100 : 8;
  uint32_t IP_101 : 8;
  uint32_t IP_102 : 8;
  uint32_t IP_103 : 8;
} PFIC_IPRIOR25_bits_t;
#define PFIC_IPRIOR25_bits (*((volatile PFIC_IPRIOR25_bits_t *)&PFIC_IPRIOR25))

#define PFIC_IPRIOR26 R32(0xE000E468)
typedef struct PFIC_IPRIOR26_bits_s {
  uint32_t IP_104 : 8;
  uint32_t IP_105 : 8;
  uint32_t IP_106 : 8;
  uint32_t IP_107 : 8;
} PFIC_IPRIOR26_bits_t;
#define PFIC_IPRIOR26_bits (*((volatile PFIC_IPRIOR26_bits_t *)&PFIC_IPRIOR26))

#define PFIC_IPRIOR27 R32(0xE000E46C)
typedef struct PFIC_IPRIOR27_bits_s {
  uint32_t IP_108 : 8;
  uint32_t IP_109 : 8;
  uint32_t IP_110 : 8;
  uint32_t IP_111 : 8;
} PFIC_IPRIOR27_bits_t;
#define PFIC_IPRIOR27_bits (*((volatile PFIC_IPRIOR27_bits_t *)&PFIC_IPRIOR27))

#define PFIC_IPRIOR28 R32(0xE000E470)
typedef struct PFIC_IPRIOR28_bits_s {
  uint32_t IP_112 : 8;
  uint32_t IP_113 : 8;
  uint32_t IP_114 : 8;
  uint32_t IP_115 : 8;
} PFIC_IPRIOR28_bits_t;
#define PFIC_IPRIOR28_bits (*((volatile PFIC_IPRIOR28_bits_t *)&PFIC_IPRIOR28))

#define PFIC_IPRIOR29 R32(0xE000E474)
typedef struct PFIC_IPRIOR29_bits_s {
  uint32_t IP_116 : 8;
  uint32_t IP_117 : 8;
  uint32_t IP_118 : 8;
  uint32_t IP_119 : 8;
} PFIC_IPRIOR29_bits_t;
#define PFIC_IPRIOR29_bits (*((volatile PFIC_IPRIOR29_bits_t *)&PFIC_IPRIOR29))

#define PFIC_IPRIOR30 R32(0xE000E478)
typedef struct PFIC_IPRIOR30_bits_s {
  uint32_t IP_120 : 8;
  uint32_t IP_121 : 8;
  uint32_t IP_122 : 8;
  uint32_t IP_123 : 8;
} PFIC_IPRIOR30_bits_t;
#define PFIC_IPRIOR30_bits (*((volatile PFIC_IPRIOR30_bits_t *)&PFIC_IPRIOR30))

#define PFIC_IPRIOR31 R32(0xE000E47C)
typedef struct PFIC_IPRIOR31_bits_s {
  uint32_t IP_124 : 8;
  uint32_t IP_125 : 8;
  uint32_t IP_126 : 8;
  uint32_t IP_127 : 8;
} PFIC_IPRIOR31_bits_t;
#define PFIC_IPRIOR31_bits (*((volatile PFIC_IPRIOR31_bits_t *)&PFIC_IPRIOR31))

#define PFIC_IPRIOR32 R32(0xE000E480)
typedef struct PFIC_IPRIOR32_bits_s {
  uint32_t IP_128 : 8;
  uint32_t IP_129 : 8;
  uint32_t IP_130 : 8;
  uint32_t IP_131 : 8;
} PFIC_IPRIOR32_bits_t;
#define PFIC_IPRIOR32_bits (*((volatile PFIC_IPRIOR32_bits_t *)&PFIC_IPRIOR32))

#define PFIC_IPRIOR33 R32(0xE000E484)
typedef struct PFIC_IPRIOR33_bits_s {
  uint32_t IP_132 : 8;
  uint32_t IP_133 : 8;
  uint32_t IP_134 : 8;
  uint32_t IP_135 : 8;
} PFIC_IPRIOR33_bits_t;
#define PFIC_IPRIOR33_bits (*((volatile PFIC_IPRIOR33_bits_t *)&PFIC_IPRIOR33))

#define PFIC_IPRIOR34 R32(0xE000E488)
typedef struct PFIC_IPRIOR34_bits_s {
  uint32_t IP_136 : 8;
  uint32_t IP_137 : 8;
  uint32_t IP_138 : 8;
  uint32_t IP_139 : 8;
} PFIC_IPRIOR34_bits_t;
#define PFIC_IPRIOR34_bits (*((volatile PFIC_IPRIOR34_bits_t *)&PFIC_IPRIOR34))

#define PFIC_IPRIOR35 R32(0xE000E48C)
typedef struct PFIC_IPRIOR35_bits_s {
  uint32_t IP_140 : 8;
  uint32_t IP_141 : 8;
  uint32_t IP_142 : 8;
  uint32_t IP_143 : 8;
} PFIC_IPRIOR35_bits_t;
#define PFIC_IPRIOR35_bits (*((volatile PFIC_IPRIOR35_bits_t *)&PFIC_IPRIOR35))

#define PFIC_IPRIOR36 R32(0xE000E490)
typedef struct PFIC_IPRIOR36_bits_s {
  uint32_t IP_144 : 8;
  uint32_t IP_145 : 8;
  uint32_t IP_146 : 8;
  uint32_t IP_147 : 8;
} PFIC_IPRIOR36_bits_t;
#define PFIC_IPRIOR36_bits (*((volatile PFIC_IPRIOR36_bits_t *)&PFIC_IPRIOR36))

#define PFIC_IPRIOR37 R32(0xE000E494)
typedef struct PFIC_IPRIOR37_bits_s {
  uint32_t IP_148 : 8;
  uint32_t IP_149 : 8;
  uint32_t IP_150 : 8;
  uint32_t IP_151 : 8;
} PFIC_IPRIOR37_bits_t;
#define PFIC_IPRIOR37_bits (*((volatile PFIC_IPRIOR37_bits_t *)&PFIC_IPRIOR37))

#define PFIC_IPRIOR38 R32(0xE000E498)
typedef struct PFIC_IPRIOR38_bits_s {
  uint32_t IP_152 : 8;
  uint32_t IP_153 : 8;
  uint32_t IP_154 : 8;
  uint32_t IP_155 : 8;
} PFIC_IPRIOR38_bits_t;
#define PFIC_IPRIOR38_bits (*((volatile PFIC_IPRIOR38_bits_t *)&PFIC_IPRIOR38))

#define PFIC_IPRIOR39 R32(0xE000E49C)
typedef struct PFIC_IPRIOR39_bits_s {
  uint32_t IP_156 : 8;
  uint32_t IP_157 : 8;
  uint32_t IP_158 : 8;
  uint32_t IP_159 : 8;
} PFIC_IPRIOR39_bits_t;
#define PFIC_IPRIOR39_bits (*((volatile PFIC_IPRIOR39_bits_t *)&PFIC_IPRIOR39))

#define PFIC_IPRIOR40 R32(0xE000E4A0)
typedef struct PFIC_IPRIOR40_bits_s {
  uint32_t IP_160 : 8;
  uint32_t IP_161 : 8;
  uint32_t IP_162 : 8;
  uint32_t IP_163 : 8;
} PFIC_IPRIOR40_bits_t;
#define PFIC_IPRIOR40_bits (*((volatile PFIC_IPRIOR40_bits_t *)&PFIC_IPRIOR40))

#define PFIC_IPRIOR41 R32(0xE000E4A4)
typedef struct PFIC_IPRIOR41_bits_s {
  uint32_t IP_164 : 8;
  uint32_t IP_165 : 8;
  uint32_t IP_166 : 8;
  uint32_t IP_167 : 8;
} PFIC_IPRIOR41_bits_t;
#define PFIC_IPRIOR41_bits (*((volatile PFIC_IPRIOR41_bits_t *)&PFIC_IPRIOR41))

#define PFIC_IPRIOR42 R32(0xE000E4A8)
typedef struct PFIC_IPRIOR42_bits_s {
  uint32_t IP_168 : 8;
  uint32_t IP_169 : 8;
  uint32_t IP_170 : 8;
  uint32_t IP_171 : 8;
} PFIC_IPRIOR42_bits_t;
#define PFIC_IPRIOR42_bits (*((volatile PFIC_IPRIOR42_bits_t *)&PFIC_IPRIOR42))

#define PFIC_IPRIOR43 R32(0xE000E4AC)
typedef struct PFIC_IPRIOR43_bits_s {
  uint32_t IP_172 : 8;
  uint32_t IP_173 : 8;
  uint32_t IP_174 : 8;
  uint32_t IP_175 : 8;
} PFIC_IPRIOR43_bits_t;
#define PFIC_IPRIOR43_bits (*((volatile PFIC_IPRIOR43_bits_t *)&PFIC_IPRIOR43))

#define PFIC_IPRIOR44 R32(0xE000E4B0)
typedef struct PFIC_IPRIOR44_bits_s {
  uint32_t IP_176 : 8;
  uint32_t IP_177 : 8;
  uint32_t IP_178 : 8;
  uint32_t IP_179 : 8;
} PFIC_IPRIOR44_bits_t;
#define PFIC_IPRIOR44_bits (*((volatile PFIC_IPRIOR44_bits_t *)&PFIC_IPRIOR44))

#define PFIC_IPRIOR45 R32(0xE000E4B4)
typedef struct PFIC_IPRIOR45_bits_s {
  uint32_t IP_180 : 8;
  uint32_t IP_181 : 8;
  uint32_t IP_182 : 8;
  uint32_t IP_183 : 8;
} PFIC_IPRIOR45_bits_t;
#define PFIC_IPRIOR45_bits (*((volatile PFIC_IPRIOR45_bits_t *)&PFIC_IPRIOR45))

#define PFIC_IPRIOR46 R32(0xE000E4B8)
typedef struct PFIC_IPRIOR46_bits_s {
  uint32_t IP_184 : 8;
  uint32_t IP_185 : 8;
  uint32_t IP_186 : 8;
  uint32_t IP_187 : 8;
} PFIC_IPRIOR46_bits_t;
#define PFIC_IPRIOR46_bits (*((volatile PFIC_IPRIOR46_bits_t *)&PFIC_IPRIOR46))

#define PFIC_IPRIOR47 R32(0xE000E4BC)
typedef struct PFIC_IPRIOR47_bits_s {
  uint32_t IP_188 : 8;
  uint32_t IP_189 : 8;
  uint32_t IP_190 : 8;
  uint32_t IP_191 : 8;
} PFIC_IPRIOR47_bits_t;
#define PFIC_IPRIOR47_bits (*((volatile PFIC_IPRIOR47_bits_t *)&PFIC_IPRIOR47))

#define PFIC_IPRIOR48 R32(0xE000E4C0)
typedef struct PFIC_IPRIOR48_bits_s {
  uint32_t IP_192 : 8;
  uint32_t IP_193 : 8;
  uint32_t IP_194 : 8;
  uint32_t IP_195 : 8;
} PFIC_IPRIOR48_bits_t;
#define PFIC_IPRIOR48_bits (*((volatile PFIC_IPRIOR48_bits_t *)&PFIC_IPRIOR48))

#define PFIC_IPRIOR49 R32(0xE000E4C4)
typedef struct PFIC_IPRIOR49_bits_s {
  uint32_t IP_196 : 8;
  uint32_t IP_197 : 8;
  uint32_t IP_198 : 8;
  uint32_t IP_199 : 8;
} PFIC_IPRIOR49_bits_t;
#define PFIC_IPRIOR49_bits (*((volatile PFIC_IPRIOR49_bits_t *)&PFIC_IPRIOR49))

#define PFIC_IPRIOR50 R32(0xE000E4C8)
typedef struct PFIC_IPRIOR50_bits_s {
  uint32_t IP_200 : 8;
  uint32_t IP_201 : 8;
  uint32_t IP_202 : 8;
  uint32_t IP_203 : 8;
} PFIC_IPRIOR50_bits_t;
#define PFIC_IPRIOR50_bits (*((volatile PFIC_IPRIOR50_bits_t *)&PFIC_IPRIOR50))

#define PFIC_IPRIOR51 R32(0xE000E4CC)
typedef struct PFIC_IPRIOR51_bits_s {
  uint32_t IP_204 : 8;
  uint32_t IP_205 : 8;
  uint32_t IP_206 : 8;
  uint32_t IP_207 : 8;
} PFIC_IPRIOR51_bits_t;
#define PFIC_IPRIOR51_bits (*((volatile PFIC_IPRIOR51_bits_t *)&PFIC_IPRIOR51))

#define PFIC_IPRIOR52 R32(0xE000E4D0)
typedef struct PFIC_IPRIOR52_bits_s {
  uint32_t IP_208 : 8;
  uint32_t IP_209 : 8;
  uint32_t IP_210 : 8;
  uint32_t IP_211 : 8;
} PFIC_IPRIOR52_bits_t;
#define PFIC_IPRIOR52_bits (*((volatile PFIC_IPRIOR52_bits_t *)&PFIC_IPRIOR52))

#define PFIC_IPRIOR53 R32(0xE000E4D4)
typedef struct PFIC_IPRIOR53_bits_s {
  uint32_t IP_212 : 8;
  uint32_t IP_213 : 8;
  uint32_t IP_214 : 8;
  uint32_t IP_215 : 8;
} PFIC_IPRIOR53_bits_t;
#define PFIC_IPRIOR53_bits (*((volatile PFIC_IPRIOR53_bits_t *)&PFIC_IPRIOR53))

#define PFIC_IPRIOR54 R32(0xE000E4D8)
typedef struct PFIC_IPRIOR54_bits_s {
  uint32_t IP_216 : 8;
  uint32_t IP_217 : 8;
  uint32_t IP_218 : 8;
  uint32_t IP_219 : 8;
} PFIC_IPRIOR54_bits_t;
#define PFIC_IPRIOR54_bits (*((volatile PFIC_IPRIOR54_bits_t *)&PFIC_IPRIOR54))

#define PFIC_IPRIOR55 R32(0xE000E4DC)
typedef struct PFIC_IPRIOR55_bits_s {
  uint32_t IP_220 : 8;
  uint32_t IP_221 : 8;
  uint32_t IP_222 : 8;
  uint32_t IP_223 : 8;
} PFIC_IPRIOR55_bits_t;
#define PFIC_IPRIOR55_bits (*((volatile PFIC_IPRIOR55_bits_t *)&PFIC_IPRIOR55))

#define PFIC_IPRIOR56 R32(0xE000E4E0)
typedef struct PFIC_IPRIOR56_bits_s {
  uint32_t IP_224 : 8;
  uint32_t IP_225 : 8;
  uint32_t IP_226 : 8;
  uint32_t IP_227 : 8;
} PFIC_IPRIOR56_bits_t;
#define PFIC_IPRIOR56_bits (*((volatile PFIC_IPRIOR56_bits_t *)&PFIC_IPRIOR56))

#define PFIC_IPRIOR57 R32(0xE000E4E4)
typedef struct PFIC_IPRIOR57_bits_s {
  uint32_t IP_228 : 8;
  uint32_t IP_229 : 8;
  uint32_t IP_230 : 8;
  uint32_t IP_231 : 8;
} PFIC_IPRIOR57_bits_t;
#define PFIC_IPRIOR57_bits (*((volatile PFIC_IPRIOR57_bits_t *)&PFIC_IPRIOR57))

#define PFIC_IPRIOR58 R32(0xE000E4E8)
typedef struct PFIC_IPRIOR58_bits_s {
  uint32_t IP_232 : 8;
  uint32_t IP_233 : 8;
  uint32_t IP_234 : 8;
  uint32_t IP_235 : 8;
} PFIC_IPRIOR58_bits_t;
#define PFIC_IPRIOR58_bits (*((volatile PFIC_IPRIOR58_bits_t *)&PFIC_IPRIOR58))

#define PFIC_IPRIOR59 R32(0xE000E4EC)
typedef struct PFIC_IPRIOR59_bits_s {
  uint32_t IP_236 : 8;
  uint32_t IP_237 : 8;
  uint32_t IP_238 : 8;
  uint32_t IP_239 : 8;
} PFIC_IPRIOR59_bits_t;
#define PFIC_IPRIOR59_bits (*((volatile PFIC_IPRIOR59_bits_t *)&PFIC_IPRIOR59))

#define PFIC_IPRIOR60 R32(0xE000E4F0)
typedef struct PFIC_IPRIOR60_bits_s {
  uint32_t IP_240 : 8;
  uint32_t IP_241 : 8;
  uint32_t IP_242 : 8;
  uint32_t IP_243 : 8;
} PFIC_IPRIOR60_bits_t;
#define PFIC_IPRIOR60_bits (*((volatile PFIC_IPRIOR60_bits_t *)&PFIC_IPRIOR60))

#define PFIC_IPRIOR61 R32(0xE000E4F4)
typedef struct PFIC_IPRIOR61_bits_s {
  uint32_t IP_244 : 8;
  uint32_t IP_245 : 8;
  uint32_t IP_246 : 8;
  uint32_t IP_247 : 8;
} PFIC_IPRIOR61_bits_t;
#define PFIC_IPRIOR61_bits (*((volatile PFIC_IPRIOR61_bits_t *)&PFIC_IPRIOR61))

#define PFIC_IPRIOR62 R32(0xE000E4F8)
typedef struct PFIC_IPRIOR62_bits_s {
  uint32_t IP_248 : 8;
  uint32_t IP_249 : 8;
  uint32_t IP_250 : 8;
  uint32_t IP_251 : 8;
} PFIC_IPRIOR62_bits_t;
#define PFIC_IPRIOR62_bits (*((volatile PFIC_IPRIOR62_bits_t *)&PFIC_IPRIOR62))

#define PFIC_IPRIOR63 R32(0xE000E4FC)
typedef struct PFIC_IPRIOR63_bits_s {
  uint32_t IP_252 : 8;
  uint32_t IP_253 : 8;
  uint32_t IP_254 : 8;
  uint32_t IP_255 : 8;
} PFIC_IPRIOR63_bits_t;
#define PFIC_IPRIOR63_bits (*((volatile PFIC_IPRIOR63_bits_t *)&PFIC_IPRIOR63))

#define PFIC_SCTLR R32(0xE000ED10)
typedef struct PFIC_SCTLR_bits_s {
  uint32_t _r0 : 1;
  uint32_t SLEEPONEXIT : 1;
  uint32_t SLEEPDEEP : 1;
  uint32_t WFITOWFE : 1;
  uint32_t SEVONPEND : 1;
  uint32_t SETEVENT : 1;
  uint32_t _r1 : 25;
  uint32_t SYSRESET : 1;
} PFIC_SCTLR_bits_t;
#define PFIC_SCTLR_bits (*((volatile PFIC_SCTLR_bits_t *)&PFIC_SCTLR))

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
