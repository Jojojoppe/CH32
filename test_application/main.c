#include <stdint.h>

int main(){

  // Default use pll
  uint32_t *rcc_cltr = (uint32_t*)0x40021000;
  uint32_t *rcc_cfgr0 = (uint32_t*)0x40021004;
  uint32_t *rcc_intr = (uint32_t*)0x40021008;
  *rcc_cfgr0 = 0x00000000;
  *rcc_cltr = 0x01000000 | (0x10<<3);
  // // Set flash latency
  uint32_t *flash_actlr = (uint32_t*)0x40022000;
  *flash_actlr = 1U;
  *rcc_intr = 0x009f0000;
  while((*rcc_cltr&0x02000000)==0U);
  *rcc_cfgr0 = 0x00000002;
  while((*rcc_cfgr0&0x0000000c)!=0x08);

  // Enable APB2 clocks for gpio D
  uint32_t *rcc_apb2pcenr = (uint32_t*)0x40021018;
  *rcc_apb2pcenr |= 0x20;

  uint32_t *gpiod_cfglr = (uint32_t*)0x40011400;
  uint32_t *gpiod_bshr = (uint32_t*)0x40011410;
  // push pull for D4
  *gpiod_cfglr &= ~(0b1111<<16);
  *gpiod_cfglr |= 0b0001<<16;

  for(;;){
    *gpiod_bshr |= 1<<4;
    for(uint32_t i=0; i<0x100000; i++);
    *gpiod_bshr |= (1<<(4+16));
    for(uint32_t i=0; i<0x100000; i++);
  }

  return 0;
}
