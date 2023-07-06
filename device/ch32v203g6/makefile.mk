CFLAGS += -march=rv32imac -mabi=ilp32e -nostdlib -flto -ffunction-sections
CFLAGS += -DCH32V203 -DCH32V203G6
LDFLAGS += -Wl,-gc-sections
PREFIX = riscv64-unknown-elf

SRCFILES := device/ch32v203g6/startup.c