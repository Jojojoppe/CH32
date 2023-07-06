#include <stdint.h>

int main() {

  // Enable APB2 clocks for gpio B and D
  uint32_t *rcc_apb2pcenr = (uint32_t *)0x40021018;
  *rcc_apb2pcenr |= 0x28;

  uint32_t *gpiob_cfghr = (uint32_t *)0x40010c04;
  uint32_t *gpiob_bshr = (uint32_t *)0x40010c10;
  uint32_t *gpiod_cfglr = (uint32_t *)0x40011400;
  uint32_t *gpiod_bshr = (uint32_t *)0x40011410;
  // push pull for D4 and B8
  *gpiob_cfghr &= ~(0b1111 << (4 * 0));
  *gpiob_cfghr |= 0b0001 << (4 * 0);
  *gpiod_cfglr &= ~(0b1111 << (4 * 4));
  *gpiod_cfglr |= 0b0001 << (4 * 4);

  for (;;) {
    *gpiob_bshr |= 1 << 8;
    *gpiod_bshr |= 1 << 4;
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
    *gpiob_bshr |= (1 << (8 + 16));
    *gpiod_bshr |= (1 << (4 + 16));
    for (uint32_t i = 0; i < 0x100000; i++)
      ;
  }

  return 0;
}
