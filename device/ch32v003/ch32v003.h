/**
 * @file ch32v003.h
 * @author Joppe Blondel
 * @date 2023-07-07
 * @brief
 */
#ifndef __H_CH32V003
#define __H_CH32V003

// #############################################################
// RCC @ 0x4002100
// #############################################################
#define RCC_CTLR R32(0x40021000)
typedef struct RCC_CTLR_bits_s {
  uint32_t HSION : 1;
  uint32_t HSIRDY : 1;
  uint32_t _r2 : 1;
  uint32_t HSITRIM : 5;
  uint32_t HSICAL : 8;
  uint32_t HSEON : 1;
  uint32_t HSERDY : 1;
  uint32_t HSEBYP : 1;
  uint32_t CSSON : 1;
  uint32_t _r1 : 4;
  uint32_t PLLON : 1;
  uint32_t PLLRDY : 1;
  uint32_t _r0 : 6;
} __attribute__((packed)) RCC_CTLR_bits_t;
#define RCC_CTLR_bits (*((volatile RCC_CTLR_bits_t *)&RCC_CTLR))

#define RCC_CFGR0 R32(0x40021004)
typedef struct RCC_CFGR0_bits_s {
  uint32_t SW : 2;
  uint32_t SWS : 2;
  uint32_t HPRE : 4;
  uint32_t _r2 : 3;
  uint32_t ADCPRE : 5;
  uint32_t PLLSRC : 1;
  uint32_t _r1 : 7;
  uint32_t MCO : 3;
  uint32_t _r0 : 5;
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
  uint32_t _r6 : 1;
  uint32_t HSIRDYF : 1;
  uint32_t HSERDYF : 1;
  uint32_t PLLRDYF : 1;
  uint32_t _r5 : 2;
  uint32_t CSSF : 1;
  uint32_t LSIRDYIE : 1;
  uint32_t _r4 : 1;
  uint32_t HSIRDYIE : 1;
  uint32_t HSERDYIE : 1;
  uint32_t PLLRDYIE : 1;
  uint32_t _r3 : 3;
  uint32_t LSIRDYC : 1;
  uint32_t _r2 : 1;
  uint32_t HSIRDYC : 1;
  uint32_t HSERDYC : 1;
  uint32_t PLLRDYC : 1;
  uint32_t _r1 : 2;
  uint32_t CSSC : 1;
  uint32_t _r0 : 8;
} __attribute__((packed)) RCC_INTR_bits_t;
#define RCC_INTR_bits (*((volatile RCC_INTR_bits_t *)&RCC_INTR))

#define RCC_APB2PRSTR R32(0x4002100c)
typedef struct RCC_APB2PRSTR_bits_s {
  uint32_t AFIORST : 1;
  uint32_t _r5 : 1;
  uint32_t IOPARST : 1;
  uint32_t _r4 : 1;
  uint32_t IOPCRST : 1;
  uint32_t IOPDRST : 1;
  uint32_t _r3 : 3;
  uint32_t ADC1RST : 1;
  uint32_t _r2 : 1;
  uint32_t TIM1RST : 1;
  uint32_t SPI1RST : 1;
  uint32_t _r1 : 1;
  uint32_t USART1RST : 1;
  uint32_t _r0 : 17;
} __attribute__((packed)) RCC_APB2PRSTR_bits_t;
#define RCC_APB2PRSTR_bits (*((volatile RCC_APB2PRSTR_bits_t *)&RCC_APB2PRSTR))

#define RCC_APB1PRSTR R32(0x40021010)
typedef struct RCC_APB1PRSTR_bits_s {
  uint32_t TIM2RST : 1;
  uint32_t _r3 : 10;
  uint32_t WWDGRST : 1;
  uint32_t _r2 : 9;
  uint32_t I2C1RST : 1;
  uint32_t _r1 : 6;
  uint32_t PWRRST : 1;
  uint32_t _r0 : 3;
} __attribute__((packed)) RCC_APB1PRSTR_bits_t;
#define RCC_APB1PRSTR_bits (*((volatile RCC_APB1PRSTR_bits_t *)&RCC_APB1PRSTR))

#define RCC_AHBPCENR R32(0x40021014)
typedef struct RCC_AHBPCENR_bits_s {
  uint32_t DMA1EN : 1;
  uint32_t _r1 : 1;
  uint32_t SRAMEN : 1;
  uint32_t _r0 : 29;
} __attribute__((packed)) RCC_AHBPCENR_bits_t;
#define RCC_AHBPCENR_bits (*((volatile RCC_AHBPCENR_bits_t *)&RCC_AHBPCENR))

#define RCC_APB2PCENR R32(0x40021018)
typedef struct RCC_APB2PCENR_bits_s {
  uint32_t AFIOEN : 1;
  uint32_t _r5 : 1;
  uint32_t IOPAEN : 1;
  uint32_t _r4 : 1;
  uint32_t IOPCEN : 1;
  uint32_t IOPDEN : 1;
  uint32_t _r3 : 3;
  uint32_t ADC1EN : 1;
  uint32_t _r2 : 1;
  uint32_t TIM1EN : 1;
  uint32_t SPI1EN : 1;
  uint32_t _r1 : 1;
  uint32_t USART1EN : 1;
  uint32_t _r0 : 17;
} __attribute__((packed)) RCC_APB2PCENR_bits_t;
#define RCC_APB2PCENR_bits (*((volatile RCC_APB2PCENR_bits_t *)&RCC_APB2PCENR))

#define RCC_APB1PCENR R32(0x4002101c)
typedef struct RCC_APB1PCENR_bits_s {
  uint32_t TIM2EN : 1;
  uint32_t _r3 : 10;
  uint32_t WWDGEN : 1;
  uint32_t _r2 : 9;
  uint32_t I2C1EN : 1;
  uint32_t _r1 : 6;
  uint32_t PWREN : 1;
  uint32_t _r0 : 3;
} __attribute__((packed)) RCC_APB1PCENR_bits_t;
#define RCC_APB1PCENR_bits (*((volatile RCC_APB1PCENR_bits_t *)&RCC_APB1PCENR))

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

// #############################################################

// #############################################################
// GPIO @ 0x40010800, 0x40011000, 0x40011400
// #############################################################

#define GPIOA_CFGLR R32(0x40010800)
#define GPIOC_CFGLR R32(0x40011000)
#define GPIOD_CFGLR R32(0x40011400)
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
#define GPIOA_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOA_CFGLR))
#define GPIOC_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOC_CFGLR))
#define GPIOD_CFGLR_bits (*((volatile GPIOx_CFGLR_bits_t *)&GPIOD_CFGLR))
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
#define GPIOC_INDR R32(0x40011008)
#define GPIOD_INDR R32(0x40011408)
typedef struct GPIOx_INDR_bits_s {
  uint32_t INDR0 : 1;
  uint32_t INDR1 : 1;
  uint32_t INDR2 : 1;
  uint32_t INDR3 : 1;
  uint32_t INDR4 : 1;
  uint32_t INDR5 : 1;
  uint32_t INDR6 : 1;
  uint32_t INDR7 : 1;
  uint32_t _r0 : 24;
} __attribute__((packed)) GPIOx_INDR_bits_t;
#define GPIOA_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOA_INDR))
#define GPIOC_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOC_INDR))
#define GPIOD_INDR_bits (*((volatile GPIOx_INDR_bits_t *)&GPIOD_INDR))

#define GPIOA_OUTDR R32(0x4001080c)
#define GPIOC_OUTDR R32(0x4001100c)
#define GPIOD_OUTDR R32(0x4001140c)
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
} __attribute__((packed)) GPIOx_OUTDR_bits_t;
#define GPIOA_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOA_OUTDR))
#define GPIOC_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOC_OUTDR))
#define GPIOD_OUTDR_bits (*((volatile GPIOx_OUTDR_bits_t *)&GPIOD_OUTDR))

#define GPIOA_BSHR R32(0x40010810)
#define GPIOC_BSHR R32(0x40011010)
#define GPIOD_BSHR R32(0x40011410)
typedef struct GPIOx_BSHR_bits_s {
  uint32_t BS0 : 1;
  uint32_t BS1 : 1;
  uint32_t BS2 : 1;
  uint32_t BS3 : 1;
  uint32_t BS4 : 1;
  uint32_t BS5 : 1;
  uint32_t BS6 : 1;
  uint32_t BS7 : 1;
  uint32_t _r1 : 8;
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t _r0 : 8;
} __attribute__((packed)) GPIOx_BSHR_bits_t;
#define GPIOA_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOA_BSHR))
#define GPIOC_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOC_BSHR))
#define GPIOD_BSHR_bits (*((volatile GPIOx_BSHR_bits_t *)&GPIOD_BSHR))

#define GPIOA_BCR R32(0x40010814)
#define GPIOC_BCR R32(0x40011014)
#define GPIOD_BCR R32(0x40011414)
typedef struct GPIOx_BCR_bits_s {
  uint32_t BR0 : 1;
  uint32_t BR1 : 1;
  uint32_t BR2 : 1;
  uint32_t BR3 : 1;
  uint32_t BR4 : 1;
  uint32_t BR5 : 1;
  uint32_t BR6 : 1;
  uint32_t BR7 : 1;
  uint32_t _r0 : 8;
  uint32_t _r1 : 16;
} __attribute__((packed)) GPIOx_BCR_bits_t;
#define GPIOA_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOA_BCR))
#define GPIOC_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOC_BCR))
#define GPIOD_BCR_bits (*((volatile GPIOx_BCR_bits_t *)&GPIOD_BCR))

#define GPIOA_LCKR R32(0x40010818)
#define GPIOC_LCKR R32(0x40011018)
#define GPIOD_LCKR R32(0x40011418)
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
} __attribute__((packed)) GPIOx_LCKR_bits_t;
#define GPIOA_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOA_LCKR))
#define GPIOC_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOC_LCKR))
#define GPIOD_LCKR_bits (*((volatile GPIOx_LCKR_bits_t *)&GPIOD_LCKR))

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
  uint32_t _r0 : 27;
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

#define STK_CMPLR R32(0xe000f0010)
// #############################################################

#endif // __H_CH32V003
