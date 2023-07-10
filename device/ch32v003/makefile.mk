CFLAGS += -march=rv32ec -mabi=ilp32e -nostdlib -flto -ffunction-sections -fstrict-volatile-bitfields
CFLAGS += -DCH32V003
LDFLAGS += -Wl,-gc-sections -lgcc
LDFILE ?= $(CH32ROOT)/device/ch32v003/linker.ld

SRCFILES += $(CH32ROOT)/device/ch32v003/startup.c