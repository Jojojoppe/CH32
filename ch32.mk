.SILENT:

DEVICE 				?= ch32v003
PART					?= g6
DEBUG					?=
PREFIX				?= riscv64-elf

include $(CH32ROOT)/device/$(DEVICE)/makefile.mk

BUILDDIR_BASE	:= build
DISTDIR_BASE	:= dist
ifeq "$(DEBUG)" ""
	BUILDDIR		:= $(BUILDDIR_BASE)/release
	DISTDIR			:= $(DISTDIR_BASE)/release
else
	CFLAGS 			+= -g -D__DEBUG -Og
	BUILDDIR		:= $(BUILDDIR_BASE)/debug
	DISTDIR			:= $(DISTDIR_BASE)/debug
endif

## ADD HAL
HAL					:= $(CH32ROOT)/device/$(DEVICE)/hal
SRCFILES			+= $(shell find $(HAL) -type f -name "*.c")

BUILDLOC			:= $(BUILDDIR)/$(TARGET)
DISTLOC				:= $(DISTDIR)/$(TARGET)

OBJFILES			:= $(SRCFILES:%.c=$(BUILDLOC)/%.c.o)
DEPFILES			:= $(SRCFILES:%.c=$(BUILDLOC)/%.c.d)

CC						:= $(PREFIX)-gcc
GDB						:= $(PREFIX)-gdb
LD						:= $(PREFIX)-gcc
AS						:= $(PREFIX)-gcc
OBJCOPY 			:= $(PREFIX)-objcopy
OBJDUMP 			:= $(PREFIX)-objdump

CFLAGS				+= -I. -I$(CH32ROOT)/include -I$(CH32ROOT)/device/$(DEVICE)
LDFLAGS				+= -Wl,--print-memory-usage -L$(CH32ROOT)/misc/libgcc

# Add DEPFILE dependencies
-include $(DEPFILES)

.PHONY: all $(TARGET)
all: $(TARGET)
$(TARGET): $(DISTLOC)/$(TARGET).elf

$(DISTLOC)/$(TARGET).elf: $(OBJFILES)
	echo 'LD ' $@
	echo $(SRCNAMES)
	-mkdir -p $(shell dirname $@)
	$(LD) $(CFLAGS) $(LDFLAGS) -T$(LDFILE) -o $@ $(OBJFILES) $(CC_LIBS)
	$(OBJDUMP) -S $@ > $(DISTLOC)/$(TARGET).lst
	$(OBJDUMP) -t $@ > $(DISTLOC)/$(TARGET).map
	$(OBJCOPY) -O binary $@ $(DISTLOC)/$(TARGET).bin
	$(OBJCOPY) -O ihex $@ $(DISTLOC)/$(TARGET).hex
	cp $(DISTLOC)/$(TARGET).bin $(DISTDIR)/last.bin

$(OBJFILES): $(BUILDLOC)/%.c.o: %.c
	echo 'CC ' $@
	-mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -MD -o $@ -c $<

.PHONY: clean
clean:
	echo ' >> clean'
	-rm -rf $(BUILDDIR_BASE) $(DISTDIR_BASE)

.PHONY: mchlink
mchlink:
	echo ' >> make mchlink'
	cd $(CH32ROOT)/misc/minichlink && make

.PHONY: flash
flash: mchlink
	echo ' >> flash'
	-$(CH32ROOT)/misc/minichlink/mchlink -w $(DISTDIR)/last.bin flash -b

.PHONY: flash_bootloader
flash_bootloader: mchlink
	echo ' >> flash_bootloader'
	-$(CH32ROOT)/misc/minichlink/mchlink -a -U -w $(DISTDIR)/last.bin bootloader -B

.PHONY: reset
reset: mchlink
	echo ' >> reset'
	-$(CH32ROOT)/misc/minichlink/mchlink -b

.PHONY: debug
debug: mchlink
	echo ' >> debug @localhost:2000'
	-$(CH32ROOT)/misc/minichlink/mchlink -w $(DISTDIR)/last.bin flash -b -A -G

.PHONY: term
term: mchlink
	echo ' >> term'
	-$(CH32ROOT)/misc/minichlink/mchlink -w $(DISTDIR)/last.bin flash -b -T 9600

.PHONY: unbrick
unbrick: mchlink
	echo ' >> unbrick'
	-$(CH32ROOT)/misc/minichlink/mchlink -u

.PHONY: header
header:
	echo ' >> header'
	cd $(CH32ROOT)/device/$(DEVICE) && python $(CH32ROOT)/scripts/genheader.py

