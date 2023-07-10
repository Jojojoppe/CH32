CFLAGS += -march=rv32imac -mabi=ilp32e -nostdlib -flto -ffunction-sections -fstrict-volatile-bitfields
CFLAGS += -DCH32V203 -DPART_$(PART)
LDFLAGS += -Wl,-gc-sections -lgcc

SRCFILES += $(CH32ROOT)/device/ch32v203/startup.c

# Check specific files
ifneq (,$(findstring $(PART), f6 g6 k6 c6))
LDFILE ?= $(CH32ROOT)/device/ch32v203/linker_32_10.ld
else ifneq (,$(findstring $(PART), f8 g8 k8 c8))
LDFILE ?= $(CH32ROOT)/device/ch32v203/linker_64_20.ld
else ifneq (,$(findstring $(PART), rb))
LDFILE ?= $(CH32ROOT)/device/ch32v203/linker_128_64.ld
else
$(error Unknown part type, choose from [f6 g6 k6 c6])
endif