/**
 * @file ch32v203.h
 * @author Joppe Blondel
 * @date 2023-07-07
 * @brief
 */
#ifndef __H_CH32V203
#define __H_CH32V203

// #############################################################
// RCC @ 0x4002100
// #############################################################
#define RCC_CTLR R32(0x40021000)
typedef struct RCC_CTLR_bits_s {
  uint32_t HSION : 1;
  uint32_t HSIRDY : 1;
  uint32_t _r3 : 1;
  uint32_t HSITRIM : 5;
  uint32_t HSICAL : 8;
  uint32_t HSEON : 1;
  uint32_t HSERDY : 1;
  uint32_t HSEBYP : 1;
  uint32_t CSSON : 1;
  uint32_t _r2 : 4;
  uint32_t PLLON : 1;
  uint32_t PLLRDY : 1;
#if defined(PART_D8C)
  uint32_t PLL2ON : 1;
  uint32_t PLL2RDY : 1;
  uint32_t PLL3ON : 1;
  uint32_t PLL3RDY : 1;
#else
  uint32_t _r1 : 4;
#endif
  uint32_t _r0 : 2;
} __attribute__((packed)) RCC_CTLR_bits_t;
#define RCC_CTLR_bits (*((volatile RCC_CTLR_bits_t *)&RCC_CTLR))

#define RCC_CFGR0 R32(0x40021004)
typedef struct RCC_CFGR0_bits_s {
  uint32_t SW : 2;
  uint32_t SWS : 2;
  uint32_t HPRE : 4;
  uint32_t PPRE1 : 3;
  uint32_t PPRE2 : 3;
  uint32_t ADCPRE : 2;
  uint32_t PLLSRC : 1;
  uint32_t PLLXTPRE : 1;
  uint32_t PLLMUL : 4;
#if defined(PART_D8W)
  uint32_t USBPRE : 2;
#else
  uint32_t _r0 : 2;
#endif
  uint32_t MCO : 4;
#if defined(PART_D8W)
  uint32_t ETHPRE : 1;
#else
  uint32_t _r1 : 1;
#endif
  uint32_t _r2 : 2;
  uint32_t ADCDUTY : 1;
} __attribute__((packed)) RCC_CFGR0_bits_t;
#define RCC_CFGR0_bits (*((volatile RCC_CFGR0_bits_t *)&RCC_CFGR0))
enum RCC_SYSCLK_SRC {
  RCC_SYSCLK_SRC_HSI = 0,
  RCC_SYSCLK_SRC_HSE = 1,
  RCC_SYSCLK_SRC_PLL = 2,
};

#define RCC_INTR R32(0x40021008)
typedef struct RCC_INTR_bits_s {
  uint32_t LSIRDYF : 1;
  uint32_t LSERDYF : 1;
  uint32_t HSIRDYF : 1;
  uint32_t HSERDYF : 1;
  uint32_t PLLRDYF : 1;
  uint32_t PLL2DRYF : 1;
  uint32_t PLL3DRYF : 1;
  uint32_t CSSF : 1;
  uint32_t LSIRDYIE : 1;
  uint32_t LSERDYIE : 1;
  uint32_t HSIRDYIE : 1;
  uint32_t HSERDYIE : 1;
  uint32_t PLLRDYIE : 1;
  uint32_t PLL2RDYIE : 1;
  uint32_t PLL3RDYIE : 1;
  uint32_t _r1 : 1;
  uint32_t LSIRDYC : 1;
  uint32_t LSERDYC : 1;
  uint32_t HSIRDYC : 1;
  uint32_t HSERDYC : 1;
  uint32_t PLLRDYC : 1;
  uint32_t PLL2RDYC : 1;
  uint32_t PLL3RDYC : 1;
  uint32_t CSSC : 1;
  uint32_t _r0 : 8;
} __attribute__((packed)) RCC_INTR_bits_t;
#define RCC_INTR_bits (*((volatile RCC_INTR_bits_t *)&RCC_INTR))

#define RCC_APB2PRSTR R32(0x4002100c)
typedef struct RCC_APB2PRSTR_bits_s {
  uint32_t AFIORST : 1;
  uint32_t _r3 : 1;
  uint32_t IOPARST : 1;
  uint32_t IOPBRST : 1;
  uint32_t IOPCRST : 1;
  uint32_t IOPDRST : 1;
  uint32_t IOPERST : 1;
  uint32_t _r2 : 2;
  uint32_t ADC1RST : 1;
  uint32_t ADC2RST : 1;
  uint32_t TIM1RST : 1;
  uint32_t SPI1RST : 1;
  uint32_t TIM8RST : 1;
  uint32_t USART1RST : 1;
  uint32_t _r1 : 4;
  uint32_t TIM9RST : 1;
  uint32_t TIM10RST : 1;
  uint32_t _r0 : 11;
} __attribute__((packed)) RCC_APB2PRSTR_bits_t;
#define RCC_APB2PRSTR_bits (*((volatile RCC_APB2PRSTR_bits_t *)&RCC_APB2PRSTR))

#define RCC_APB1PRSTR R32(0x40021010)
typedef struct RCC_APB1PRSTR_bits_s {
  uint32_t TIM2RST : 1;
  uint32_t TIM3RST : 1;
  uint32_t TIM4RST : 1;
  uint32_t TIM5RST : 1;
  uint32_t TIM6RST : 1;
  uint32_t TIM7RST : 1;
  uint32_t UART6RST : 1;
  uint32_t UART7RST : 1;
  uint32_t UART8RST : 1;
  uint32_t _r4 : 2;
  uint32_t WWDGRST : 1;
  uint32_t _r3 : 2;
  uint32_t SPI2RST : 1;
  uint32_t SPI3RST : 1;
  uint32_t _r2 : 1;
  uint32_t USART2RST : 1;
  uint32_t USART3RST : 1;
  uint32_t UART4RST : 1;
  uint32_t UART5RST : 1;
  uint32_t I2C1RST : 1;
  uint32_t I2C2RST : 1;
  uint32_t USBDRST : 1;
  uint32_t _r1 : 1;
  uint32_t CAN1RST : 1;
  uint32_t CAN2RST : 1;
  uint32_t BKPRST : 1;
  uint32_t PWRRST : 1;
  uint32_t DACRST : 1;
  uint32_t _r0 : 2;
} __attribute__((packed)) RCC_APB1PRSTR_bits_t;
#define RCC_APB1PRSTR_bits (*((volatile RCC_APB1PRSTR_bits_t *)&RCC_APB1PRSTR))

#define RCC_AHBPCENR R32(0x40021014)
typedef struct RCC_AHBPCENR_bits_s {
  uint32_t DMA1EN : 1;
  uint32_t DMA2EN : 1;
  uint32_t SRAMEN : 1;
  uint32_t _r4 : 3;
  uint32_t CRCEN : 1;
  uint32_t _r3 : 1;
  uint32_t FSMCEN : 1;
  uint32_t RNGEN : 1;
  uint32_t SDIOEN : 1;
  uint32_t USBHSEN : 1;
  uint32_t OTG_FSEN : 1;
  uint32_t DVPEN : 1;
#if defined(PAT_D8C)
  uint32_t ETHMACEN : 1;
  uint32_t ETHMACTXEN : 1;
  uint32_t ETHMACRXEN : 1;
#else
  uint32_t _r2 : 3;
#endif
#if defined(PART_D8W)
  uint32_t BLEC : 1;
  uint32_t BLEN : 1;
#else
  uint32_t _r1 : 2;
#endif
  uint32_t _r0 : 14;
} __attribute__((packed)) RCC_AHBPCENR_bits_t;
#define RCC_AHBPCENR_bits (*((volatile RCC_AHBPCENR_bits_t *)&RCC_AHBPCENR))

#define RCC_APB2PCENR R32(0x40021018)
typedef struct RCC_APB2PCENR_bits_s {
  uint32_t AFIOEN : 1;
  uint32_t _r3 : 1;
  uint32_t IOPAEN : 1;
  uint32_t IOPBEN : 1;
  uint32_t IOPCEN : 1;
  uint32_t IOPDEN : 1;
  uint32_t IOPEEN : 1;
  uint32_t _r2 : 2;
  uint32_t ADC1EN : 1;
  uint32_t ADC2EN : 1;
  uint32_t TIM1EN : 1;
  uint32_t SPI1EN : 1;
  uint32_t TIM8EN : 1;
  uint32_t USART1EN : 1;
  uint32_t _r1 : 4;
  uint32_t TIM9EN : 1;
  uint32_t TIM10EN : 1;
  uint32_t _r0 : 11;
} __attribute__((packed)) RCC_APB2PCENR_bits_t;
#define RCC_APB2PCENR_bits (*((volatile RCC_APB2PCENR_bits_t *)&RCC_APB2PCENR))

#define RCC_APB1PCENR R32(0x4002101c)
typedef struct RCC_APB1PCENR_bits_s {
  uint32_t TIM2EN : 1;
  uint32_t TIM3EN : 1;
  uint32_t TIM4EN : 1;
  uint32_t TIM5EN : 1;
  uint32_t TIM6EN : 1;
  uint32_t TIM7EN : 1;
  uint32_t UART6EN : 1;
  uint32_t UART7EN : 1;
  uint32_t UART8EN : 1;
  uint32_t _r4 : 2;
  uint32_t WWDGEN : 1;
  uint32_t _r3 : 2;
  uint32_t SPI2EN : 1;
  uint32_t SPI3EN : 1;
  uint32_t _r2 : 1;
  uint32_t USART2EN : 1;
  uint32_t USART3EN : 1;
  uint32_t UART4EN : 1;
  uint32_t UART5EN : 1;
  uint32_t I2C1EN : 1;
  uint32_t I2C2EN : 1;
  uint32_t USBDEN : 1;
  uint32_t _r1 : 1;
  uint32_t CAN1EN : 1;
  uint32_t CAN2EN : 1;
  uint32_t BKPEN : 1;
  uint32_t PWREN : 1;
  uint32_t DACEN : 1;
  uint32_t _r0 : 2;
} __attribute__((packed)) RCC_APB1PCENR_bits_t;
#define RCC_APB1PCENR_bits (*((volatile RCC_APB1PCENR_bits_t *)&RCC_APB1PCENR))

#define RCC_BDCTRL R32(0x40021020)
typedef struct RCC_BDCTRL_bits_s {
  uint32_t LSEON : 1;
  uint32_t LSERDY : 1;
  uint32_t LSEBYP : 1;
  uint32_t _r0 : 5;
  uint32_t RTCSEL : 2;
  uint32_t _r1 : 5;
  uint32_t RTCEN : 1;
  uint32_t BDRST : 1;
  uint32_t _r2 : 15;
} __attribute__((packed)) RCC_BDCTRL_bits_t;
#define RCC_BDCTL_bits (*((volatile RCC_BDCTL_bits_t *)&RCC_BDCTRL))
enum RCC_RTC_SOURCE {
  RCC_RTC_SOURCE_NO_CLOCK = 0,
  RCC_RTC_SOURCE_LSE = 1,
  RCC_RTC_SOURCE_LSI = 2,
  RCC_RTC_SOURCE_HSE = 3,
};

#define RCC_RSTSCKR R32(0x40021024)
typedef struct RCC_RSTSCKR_bits_s {
  uint32_t LSION : 1;
  uint32_t LSIRDY : 1;
  uint32_t _r1 : 22;
  uint32_t RMVF : 1;
  uint32_t _r0 : 1;
  uint32_t PINRSTF : 1;
  uint32_t PORRSTF : 1;
  uint32_t SFTRSTF : 1;
  uint32_t IWDGRSTF : 1;
  uint32_t WWDGRSTF : 1;
  uint32_t LPWRRSTF : 1;
} __attribute__((packed)) RCC_RSTSCKR_bits_t;
#define RCC_RSTSCKR_bits (*((volatile RCC_RSTSCKR_bits_t *)&RCC_RSTSCKR))

#define RCC_AHBRSTR R32(0x40021028)
typedef struct RCC_AHBRSTR_bits_s {
  uint32_t _r0 : 12;
  uint32_t OTGFSRST : 1;
  uint32_t DVPRST : 1;
  uint32_t ETHMACRST : 1;
  uint32_t _r : 17;
} __attribute__((packed)) RCC_AHBRSTR_bits_t;
#define RCC_AHBRSTR_bits (*((volatile RCC_AHBRSTR_bits_t *)&RCC_AHBRSTR))

#define RCC_CFGR2 R32(0x40021028)
typedef struct RCC_CFGR2_bits_s {
  uint32_t PREDIV1 : 4;
  uint32_t PREDIV2 : 4;
  uint32_t PLL2MUL : 4;
  uint32_t PLL3MUL : 4;
  uint32_t PREDIV1SRC : 1;
  uint32_t I2S2SRC : 1;
  uint32_t I2S3SRC : 1;
  uint32_t RNGSRC : 1;
  uint32_t ETH1SERC : 2;
  uint32_t ETH1GEN : 1;
  uint32_t _r0 : 1;
  uint32_t USBHSDIV : 3;
  uint32_t USBHSPLL_SRC : 1;
  uint32_t USBHSCLK : 2;
  uint32_t USBHSPLL : 1;
  uint32_t USBHSSRC : 1;
} __attribute__((packed)) RCC_CFGR2_bits_t;
#define RCC_CFGR2_bits (*((volatile RCC_CFGR2_bits_t *)&RCC_CFGR2))

// #############################################################

// #############################################################
// GPIO @ 0x40010800, 0x40010c00, 0x40011000, 0x40011400,
// 0x40011800
// #############################################################

#define GPIOA_CFGLR R32(0x40010800)
#define GPIOB_CFGLR R32(0x40010c00)
#define GPIOC_CFGLR R32(0x40011000)
#define GPIOD_CFGLR R32(0x40011400)
#define GPIOE_CFGLR R32(0x40011800)
#define GPIOA_CFGHR R32(0x40010804)
#define GPIOB_CFGHR R32(0x40010c04)
#define GPIOC_CFGHR R32(0x40011004)
#define GPIOD_CFGHR R32(0x40011404)
#define GPIOE_CFGHR R32(0x40011804)
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
} __attribute__((packed)) GPIOx_CFGLR_bits_t;
typedef struct GPIOx_CFGHR_bits_s {
  uint32_t MODE8 : 2;
  uint32_t CNF8 : 2;
  uint32_t MODE9 : 2;
  uint32_t CNF9 : 2;
  uint32_t MODE10 : 2;
  uint32_t CNF10 : 2;
  uint32_t MODE11 : 2;
  uint32_t CNF11 : 2;
  uint32_t MODE12 : 2;
  uint32_t CNF12 : 2;
  uint32_t MODE13 : 2;
  uint32_t CNF13 : 2;
  uint32_t MODE14 : 2;
  uint32_t CNF14 : 2;
  uint32_t MODE15 : 2;
  uint32_t CNF15 : 2;
} __attribute__((packed)) GPIOx_CFGHR_bits_t;
#define GPIOA_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOA_CFGLR))
#define GPIOB_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOB_CFGLR))
#define GPIOC_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOC_CFGLR))
#define GPIOD_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOD_CFGLR))
#define GPIOE_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOE_CFGLR))
#define GPIOA_CFGHR_bits (*((volatile GPIOx_CFGHR_bits_t *)&GPIOA_CFGHR))
#define GPIOB_CFGHR_bits (*((volatile GPIOx_CFGHR_bits_t *)&GPIOB_CFGHR))
#define GPIOC_CFGHR_bits (*((volatile GPIOx_CFGHR_bits_t *)&GPIOC_CFGHR))
#define GPIOD_CFGHR_bits (*((volatile GPIOx_CFGHR_bits_t *)&GPIOD_CFGHR))
#define GPIOE_CFGHR_bits (*((volatile GPIOx_CFGHR_bits_t *)&GPIOE_CFGHR))
enum GPIO_MODE {
  GPIO_MODE_INPUT = 0,
  GPIO_MODE_OUTPUT_10MHZ = 1,
  GPIO_MODE_OUTPUT_2MHZ = 2,
  GPIO_MODE_OUTPUT_50MHZ = 3,
};
enum GPIO_CNF_INPUT {
  GPIO_CNF_INPUT_ANALOG = 0,
  GPIO_CNF_INPUT_FLOATING = 1,
  GPIO_CNF_INPUT_PU_RD_MODE = 2,
};
enum GPIO_CNF_OUTPUT {
  GPIO_CNF_OUTPUT_PUSH_PULL = 0,
  GPIO_CNF_OUTPUT_OPEN_DRAIN = 1,
  GPIO_CNF_OUTPUT_FUNC_PUSH_PULL = 2,
  GPIO_CNF_OUTPUT_FUNC_OPEN_DRAIN = 3,
};

#define GPIOA_INDR R32(0x40010808)
#define GPIOB_INDR R32(0x40010c08)
#define GPIOC_INDR R32(0x40011008)
#define GPIOD_INDR R32(0x40011408)
#define GPIOE_INDR R32(0x40011808)
typedef struct GPIOx_INDR_bits_s {
  uint32_t INDR0 : 1;
  uint32_t INDR1 : 1;
  uint32_t INDR2 : 1;
  uint32_t INDR3 : 1;
  uint32_t INDR4 : 1;
  uint32_t INDR5 : 1;
  uint32_t INDR6 : 1;
  uint32_t INDR7 : 1;
  uint32_t INDR8 : 1;
  uint32_t INDR9 : 1;
  uint32_t INDR10 : 1;
  uint32_t INDR11 : 1;
  uint32_t INDR12 : 1;
  uint32_t INDR13 : 1;
  uint32_t INDR14 : 1;
  uint32_t INDR15 : 1;
  uint32_t _r0 : 16;
} __attribute__((packed)) GPIOx_INDR_bits_t;
#define GPIOA_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOA_INDR))
#define GPIOB_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOB_INDR))
#define GPIOC_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOC_INDR))
#define GPIOD_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOD_INDR))
#define GPIOE_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOE_INDR))

#define GPIOA_OUTDR R32(0x4001080c)
#define GPIOB_OUTDR R32(0x40010c0c)
#define GPIOC_OUTDR R32(0x4001100c)
#define GPIOD_OUTDR R32(0x4001140c)
#define GPIOE_OUTDR R32(0x4001180c)
typedef struct GPIOx_OUTDR_bits_s {
  uint32_t ODR0 : 1;
  uint32_t ODR1 : 1;
  uint32_t ODR2 : 1;
  uint32_t ODR3 : 1;
  uint32_t ODR4 : 1;
  uint32_t ODR5 : 1;
  uint32_t ODR6 : 1;
  uint32_t ODR7 : 1;
  uint32_t ODR8 : 1;
  uint32_t ODR9 : 1;
  uint32_t ODR10 : 1;
  uint32_t ODR11 : 1;
  uint32_t ODR12 : 1;
  uint32_t ODR13 : 1;
  uint32_t ODR14 : 1;
  uint32_t ODR15 : 1;
  uint32_t _r0 : 16;
} __attribute__((packed)) GPIOx_OUTDR_bits_t;
#define GPIOA_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOA_OUTDR))
#define GPIOB_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOB_OUTDR))
#define GPIOC_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOC_OUTDR))
#define GPIOD_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOD_OUTDR))
#define GPIOE_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOE_OUTDR))

#define GPIOA_BSHR R32(0x40010810)
#define GPIOB_BSHR R32(0x40010c10)
#define GPIOC_BSHR R32(0x40011010)
#define GPIOD_BSHR R32(0x40011410)
#define GPIOE_BSHR R32(0x40011810)
typedef struct GPIOx_BSHR_bits_s {
  uint32_t BS0 : 1;
  uint32_t BS1 : 1;
  uint32_t BS2 : 1;
  uint32_t BS3 : 1;
  uint32_t BS4 : 1;
  uint32_t BS5 : 1;
  uint32_t BS6 : 1;
  uint32_t BS7 : 1;
  uint32_t BS8 : 1;
  uint32_t BS9 : 1;
  uint32_t BS10 : 1;
  uint32_t BS11 : 1;
  uint32_t BS12 : 1;
  uint32_t BS13 : 1;
  uint32_t BS14 : 1;
  uint32_t BS15 : 1;
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t BR8 : 1;
  uint32_t BR9 : 1;
  uint32_t BR10 : 1;
  uint32_t BR11 : 1;
  uint32_t BR12 : 1;
  uint32_t BR13 : 1;
  uint32_t BR14 : 1;
  uint32_t BR15 : 1;
} __attribute__((packed)) GPIOx_BSHR_bits_t;
#define GPIOA_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOA_BSHR))
#define GPIOB_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOE_BSHR))
#define GPIOC_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOC_BSHR))
#define GPIOD_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOD_BSHR))
#define GPIOE_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOE_BSHR))

#define GPIOA_BCR R32(0x40010814)
#define GPIOB_BCR R32(0x40010c14)
#define GPIOC_BCR R32(0x40011014)
#define GPIOD_BCR R32(0x40011414)
#define GPIOE_BCR R32(0x40011814)
typedef struct GPIOx_BCR_bits_s {
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t BR8 : 1;
  uint32_t BR9 : 1;
  uint32_t BR10 : 1;
  uint32_t BR11 : 1;
  uint32_t BR12 : 1;
  uint32_t BR13 : 1;
  uint32_t BR14 : 1;
  uint32_t BR15 : 1;
  uint32_t _r1 : 16;
} __attribute__((packed)) GPIOx_BCR_bits_t;
#define GPIOA_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOA_BCR))
#define GPIOB_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOB_BCR))
#define GPIOC_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOC_BCR))
#define GPIOD_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOD_BCR))
#define GPIOE_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOE_BCR))

#define GPIOA_LCKR R32(0x40010818)
#define GPIOB_LCKR R32(0x40010c18)
#define GPIOC_LCKR R32(0x40011018)
#define GPIOD_LCKR R32(0x40011418)
#define GPIOE_LCKR R32(0x40011818)
typedef struct GPIOx_LCKR_bits_s {
  uint32_t LCK0 : 1;
  uint32_t LCK1 : 1;
  uint32_t LCK2 : 1;
  uint32_t LCK3 : 1;
  uint32_t LCK4 : 1;
  uint32_t LCK5 : 1;
  uint32_t LCK6 : 1;
  uint32_t LCK7 : 1;
  uint32_t LCK8 : 1;
  uint32_t LCK9 : 1;
  uint32_t LCK10 : 1;
  uint32_t LCK11 : 1;
  uint32_t LCK12 : 1;
  uint32_t LCK13 : 1;
  uint32_t LCK14 : 1;
  uint32_t LCK15 : 1;
  uint32_t LCKK : 1;
  uint32_t _r0 : 15;
} __attribute__((packed)) GPIOx_LCKR_bits_t;
#define GPIOA_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOA_LCKR))
#define GPIOB_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOB_LCKR))
#define GPIOC_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOC_LCKR))
#define GPIOD_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOD_LCKR))
#define GPIOE_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOE_LCKR))
// #############################################################

// #############################################################
// System counter @ 0xe000f000
// #############################################################
#define STK_CTLR R32(0xe000f000)
typedef struct STK_CTLR_bits_s {
  uint32_t STE : 1;
  uint32_t STIE : 1;
  uint32_t STCLK : 1;
  uint32_t STRE : 1;
  uint32_t MODE : 1;
  uint32_t INIT : 1;
  uint32_t _r0 : 25;
  uint32_t SWIE : 1;
} __attribute__((packed)) STK_CTLR_bits_t;
#define STK_CTLR_bits (*((volatile STK_CTLR_bits_t *)&STK_CTLR))

#define STK_SR R32(0xe000f004)
typedef struct STK_SR_bits_s {
  uint32_t CNTIF : 1;
  uint32_t _r0 : 31;
} __attribute__((packed)) STK_SR_bits_t;
#define STK_SR_bits (*((volatile STK_SR_bits_t *)&STK_SR))

#define STK_CNTL R32(0xe000f008)
#define STK_CNTH R32(0xe000f00c)

#define STK_CMPLR R32(0xe000f0010)
#define STK_CMPHR R32(0xe000f0014)
// #############################################################

#endif // __H_CH32V203
