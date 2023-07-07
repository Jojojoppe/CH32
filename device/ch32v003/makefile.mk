CFLAGS += -march=rv32ec -mabi=ilp32e -nostdlib -flto -ffunction-sections
CFLAGS += -DCH32V003
LDFLAGS += -Wl,-gc-sections -T $(CH32ROOT)/device/ch32v003/linker.ld -lgcc
PREFIX = riscv64-unknown-elf

SRCFILES += $(CH32ROOT)/device/ch32v003/startup.c