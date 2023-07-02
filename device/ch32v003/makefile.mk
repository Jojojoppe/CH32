CFLAGS += -march=rv32ec -mabi=ilp32e -nostdlib -flto -ffunction-sections
LDFLAGS += -Wl,-gc-sections
PREFIX = riscv64-unknown-elf

SRCFILES := device/ch32v003/startup.c