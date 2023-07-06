CFLAGS += -march=rv32imac -mabi=ilp32e -nostdlib -flto -ffunction-sections
LDFLAGS += -Wl,-gc-sections
PREFIX = riscv64-unknown-elf

SRCFILES := device/ch32v203g6/startup.c