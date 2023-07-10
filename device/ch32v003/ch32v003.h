#ifndef __H_CH32V003
#define __H_CH32V003

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

#define AFIO_EXTICR R32(0x40010008)

#define EXTI_INTENR R32(0x40010400)

#define EXTI_EVENR R32(0x40010404)

#define EXTI_RTENR R32(0x40010408)

#define EXTI_FTENR R32(0x4001040C)

#define EXTI_SWIEVR R32(0x40010410)

#define EXTI_INTFR R32(0x40010414)

#define GPIOA_CFGLR R32(0x40010800)

#define GPIOA_INDR R32(0x40010808)

#define GPIOA_OUTDR R32(0x4001080C)

#define GPIOA_BSHR R32(0x40010810)

#define GPIOA_BCR R32(0x40010814)

#define GPIOA_LCKR R32(0x40010818)

#define GPIOC_CFGLR R32(0x40011000)

#define GPIOC_INDR R32(0x40011008)

#define GPIOC_OUTDR R32(0x4001100C)

#define GPIOC_BSHR R32(0x40011010)

#define GPIOC_BCR R32(0x40011014)

#define GPIOC_LCKR R32(0x40011018)

#define GPIOD_CFGLR R32(0x40011400)

#define GPIOD_INDR R32(0x40011408)

#define GPIOD_OUTDR R32(0x4001140C)

#define GPIOD_BSHR R32(0x40011410)

#define GPIOD_BCR R32(0x40011414)

#define GPIOD_LCKR R32(0x40011418)

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
  uint32_t PE : 1;
  uint32_t FE : 1;
  uint32_t NE : 1;
  uint32_t ORE : 1;
  uint32_t IDLE : 1;
  uint32_t RXNE : 1;
  uint32_t TC : 1;
  uint32_t TXE : 1;
  uint32_t LBD : 1;
  uint32_t CTS : 1;
  uint32_t _r0 : 22;
} USART_STATR_bits_t;
#define USART_STATR_bits (*((volatile USART_STATR_bits_t *)&USART_STATR))

#define USART_DATAR R32(0x40013804)
typedef struct USART_DATAR_bits_s {
  union {
    uint32_t DR : 9;
    struct {
      uint32_t DR__b0 : 1;
      uint32_t DR__b1 : 1;
      uint32_t DR__b2 : 1;
      uint32_t DR__b3 : 1;
      uint32_t DR__b4 : 1;
      uint32_t DR__b5 : 1;
      uint32_t DR__b6 : 1;
      uint32_t DR__b7 : 1;
      uint32_t DR__b8 : 1;
    };
  };
  uint32_t _r0 : 23;
} USART_DATAR_bits_t;
#define USART_DATAR_bits (*((volatile USART_DATAR_bits_t *)&USART_DATAR))

#define USART_BRR R32(0x40013808)
typedef struct USART_BRR_bits_s {
  union {
    uint32_t DIV_Fraction : 4;
    struct {
      uint32_t DIV_Fraction__b0 : 1;
      uint32_t DIV_Fraction__b1 : 1;
      uint32_t DIV_Fraction__b2 : 1;
      uint32_t DIV_Fraction__b3 : 1;
    };
  };
  union {
    uint32_t DIV_Mantissa : 12;
    struct {
      uint32_t DIV_Mantissa__b0 : 1;
      uint32_t DIV_Mantissa__b1 : 1;
      uint32_t DIV_Mantissa__b2 : 1;
      uint32_t DIV_Mantissa__b3 : 1;
      uint32_t DIV_Mantissa__b4 : 1;
      uint32_t DIV_Mantissa__b5 : 1;
      uint32_t DIV_Mantissa__b6 : 1;
      uint32_t DIV_Mantissa__b7 : 1;
      uint32_t DIV_Mantissa__b8 : 1;
      uint32_t DIV_Mantissa__b9 : 1;
      uint32_t DIV_Mantissa__b10 : 1;
      uint32_t DIV_Mantissa__b11 : 1;
    };
  };
  uint32_t _r0 : 16;
} USART_BRR_bits_t;
#define USART_BRR_bits (*((volatile USART_BRR_bits_t *)&USART_BRR))

#define USART_CTLR1 R32(0x4001380c)
typedef struct USART_CTLR1_bits_s {
  uint32_t SBK : 1;
  uint32_t RWU : 1;
  uint32_t RE : 1;
  uint32_t TE : 1;
  uint32_t IDLEIE : 1;
  uint32_t RXNEIE : 1;
  uint32_t TCIE : 1;
  uint32_t TXEIE : 1;
  uint32_t PEIE : 1;
  uint32_t PS : 1;
  uint32_t PCE : 1;
  uint32_t WAKE : 1;
  uint32_t M : 1;
  uint32_t UE : 1;
  uint32_t _r0 : 18;
} USART_CTLR1_bits_t;
#define USART_CTLR1_bits (*((volatile USART_CTLR1_bits_t *)&USART_CTLR1))

#define USART_CTLR2 R32(0x40013810)
typedef struct USART_CTLR2_bits_s {
  union {
    uint32_t ADD : 4;
    struct {
      uint32_t ADD__b0 : 1;
      uint32_t ADD__b1 : 1;
      uint32_t ADD__b2 : 1;
      uint32_t ADD__b3 : 1;
    };
  };
  uint32_t _r0 : 1;
  uint32_t LBDL : 1;
  uint32_t LBDIE : 1;
  uint32_t _r1 : 1;
  uint32_t LBCL : 1;
  uint32_t CPHA : 1;
  uint32_t CPOL : 1;
  uint32_t CLKEN : 1;
  union {
    uint32_t STOP : 2;
    struct {
      uint32_t STOP__b0 : 1;
      uint32_t STOP__b1 : 1;
    };
  };
  uint32_t LINEN : 1;
  uint32_t _r2 : 17;
} USART_CTLR2_bits_t;
#define USART_CTLR2_bits (*((volatile USART_CTLR2_bits_t *)&USART_CTLR2))

#define USART_CTLR3 R32(0x40013814)
typedef struct USART_CTLR3_bits_s {
  uint32_t EIE : 1;
  uint32_t IREN : 1;
  uint32_t IRLP : 1;
  uint32_t HDSEL : 1;
  uint32_t NACK : 1;
  uint32_t SCEN : 1;
  uint32_t DMAR : 1;
  uint32_t DMAT : 1;
  uint32_t RTSE : 1;
  uint32_t CTSE : 1;
  uint32_t CTSIE : 1;
  uint32_t _r0 : 21;
} USART_CTLR3_bits_t;
#define USART_CTLR3_bits (*((volatile USART_CTLR3_bits_t *)&USART_CTLR3))

#define USART_GPR R32(0x40013818)
typedef struct USART_GPR_bits_s {
  union {
    uint32_t PSC : 8;
    struct {
      uint32_t PSC__b0 : 1;
      uint32_t PSC__b1 : 1;
      uint32_t PSC__b2 : 1;
      uint32_t PSC__b3 : 1;
      uint32_t PSC__b4 : 1;
      uint32_t PSC__b5 : 1;
      uint32_t PSC__b6 : 1;
      uint32_t PSC__b7 : 1;
    };
  };
  union {
    uint32_t GT : 8;
    struct {
      uint32_t GT__b0 : 1;
      uint32_t GT__b1 : 1;
      uint32_t GT__b2 : 1;
      uint32_t GT__b3 : 1;
      uint32_t GT__b4 : 1;
      uint32_t GT__b5 : 1;
      uint32_t GT__b6 : 1;
      uint32_t GT__b7 : 1;
    };
  };
  uint32_t _r0 : 16;
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
  union {
    uint32_t HSITRIM : 5;
    struct {
      uint32_t HSITRIM__b0 : 1;
      uint32_t HSITRIM__b1 : 1;
      uint32_t HSITRIM__b2 : 1;
      uint32_t HSITRIM__b3 : 1;
      uint32_t HSITRIM__b4 : 1;
    };
  };
  uint32_t _r1 : 8;
  uint32_t HSEON : 1;
  uint32_t HSERDY : 1;
  uint32_t HSEBYP : 1;
  uint32_t CSSON : 1;
  uint32_t _r2 : 4;
  uint32_t PLLON : 1;
  uint32_t PLLRDY : 1;
  uint32_t _r3 : 6;
} RCC_CTLR_bits_t;
#define RCC_CTLR_bits (*((volatile RCC_CTLR_bits_t *)&RCC_CTLR))

#define RCC_CFGR0 R32(0x40021004)
typedef struct RCC_CFGR0_bits_s {
  union {
    uint32_t SW : 2;
    struct {
      uint32_t SW__b0 : 1;
      uint32_t SW__b1 : 1;
    };
  };
  union {
    uint32_t SWS : 2;
    struct {
      uint32_t SWS__b0 : 1;
      uint32_t SWS__b1 : 1;
    };
  };
  union {
    uint32_t HPRE : 4;
    struct {
      uint32_t HPRE__b0 : 1;
      uint32_t HPRE__b1 : 1;
      uint32_t HPRE__b2 : 1;
      uint32_t HPRE__b3 : 1;
    };
  };
  uint32_t _r0 : 3;
  union {
    uint32_t ADCPRE : 5;
    struct {
      uint32_t ADCPRE__b0 : 1;
      uint32_t ADCPRE__b1 : 1;
      uint32_t ADCPRE__b2 : 1;
      uint32_t ADCPRE__b3 : 1;
      uint32_t ADCPRE__b4 : 1;
    };
  };
  uint32_t PLLSRC : 1;
  uint32_t _r1 : 7;
  union {
    uint32_t MCO : 3;
    struct {
      uint32_t MCO__b0 : 1;
      uint32_t MCO__b1 : 1;
      uint32_t MCO__b2 : 1;
    };
  };
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
  uint32_t _r2 : 0;
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
  uint32_t _r1 : 0;
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
  union {
    uint32_t CNT : 32;
    struct {
      uint32_t CNT__b0 : 1;
      uint32_t CNT__b1 : 1;
      uint32_t CNT__b2 : 1;
      uint32_t CNT__b3 : 1;
      uint32_t CNT__b4 : 1;
      uint32_t CNT__b5 : 1;
      uint32_t CNT__b6 : 1;
      uint32_t CNT__b7 : 1;
      uint32_t CNT__b8 : 1;
      uint32_t CNT__b9 : 1;
      uint32_t CNT__b10 : 1;
      uint32_t CNT__b11 : 1;
      uint32_t CNT__b12 : 1;
      uint32_t CNT__b13 : 1;
      uint32_t CNT__b14 : 1;
      uint32_t CNT__b15 : 1;
      uint32_t CNT__b16 : 1;
      uint32_t CNT__b17 : 1;
      uint32_t CNT__b18 : 1;
      uint32_t CNT__b19 : 1;
      uint32_t CNT__b20 : 1;
      uint32_t CNT__b21 : 1;
      uint32_t CNT__b22 : 1;
      uint32_t CNT__b23 : 1;
      uint32_t CNT__b24 : 1;
      uint32_t CNT__b25 : 1;
      uint32_t CNT__b26 : 1;
      uint32_t CNT__b27 : 1;
      uint32_t CNT__b28 : 1;
      uint32_t CNT__b29 : 1;
      uint32_t CNT__b30 : 1;
      uint32_t CNT__b31 : 1;
    };
  };
  uint32_t _r0 : 0;
} STK_CNTL_bits_t;
#define STK_CNTL_bits (*((volatile STK_CNTL_bits_t *)&STK_CNTL))

#define STK_CMPLR R32(0xE000F010)
typedef struct STK_CMPLR_bits_s {
  union {
    uint32_t CMP : 32;
    struct {
      uint32_t CMP__b0 : 1;
      uint32_t CMP__b1 : 1;
      uint32_t CMP__b2 : 1;
      uint32_t CMP__b3 : 1;
      uint32_t CMP__b4 : 1;
      uint32_t CMP__b5 : 1;
      uint32_t CMP__b6 : 1;
      uint32_t CMP__b7 : 1;
      uint32_t CMP__b8 : 1;
      uint32_t CMP__b9 : 1;
      uint32_t CMP__b10 : 1;
      uint32_t CMP__b11 : 1;
      uint32_t CMP__b12 : 1;
      uint32_t CMP__b13 : 1;
      uint32_t CMP__b14 : 1;
      uint32_t CMP__b15 : 1;
      uint32_t CMP__b16 : 1;
      uint32_t CMP__b17 : 1;
      uint32_t CMP__b18 : 1;
      uint32_t CMP__b19 : 1;
      uint32_t CMP__b20 : 1;
      uint32_t CMP__b21 : 1;
      uint32_t CMP__b22 : 1;
      uint32_t CMP__b23 : 1;
      uint32_t CMP__b24 : 1;
      uint32_t CMP__b25 : 1;
      uint32_t CMP__b26 : 1;
      uint32_t CMP__b27 : 1;
      uint32_t CMP__b28 : 1;
      uint32_t CMP__b29 : 1;
      uint32_t CMP__b30 : 1;
      uint32_t CMP__b31 : 1;
    };
  };
  uint32_t _r0 : 0;
} STK_CMPLR_bits_t;
#define STK_CMPLR_bits (*((volatile STK_CMPLR_bits_t *)&STK_CMPLR))
#endif // __H_CH32V003
