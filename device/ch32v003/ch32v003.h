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
#define RCC_CLTR R32(0x40021000)
typedef struct RCC_CLTR_bits_s {
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
} __attribute__((packed)) RCC_CLTR_bits_t;
#define RCC_CLTR_bits (*((volatile RCC_CLTR_bits_t *)&RCC_CLTR))

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

#endif // __H_CH32V003
