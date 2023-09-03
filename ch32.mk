.SILENT:

DEVICE 				?= ch32v203
PART					?= g6
DEBUG					?=
PREFIX					?= riscv64-elf

include $(CH32ROOT)/device/$(DEVICE)/makefile.mk

BUILDDIR_BASE	:= build
DISTDIR_BASE	:= dist
ifeq "$(DEBUG)" ""
	BUILDDIR		:= $(BUILDDIR_BASE)/release
	DISTDIR			:= $(DISTDIR_BASE)/release
else
	CFLAGS 			+= -g
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
LDFLAGS				+= -Wl,--print-memory-usage

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

$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink:
	cd $(CH32ROOT)/extern/ch32v003fun/minichlink && \
		${MAKE} ${MFLAGS} minichlink

.PHONY: flash
flash: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> flash'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -w $(DISTDIR)/last.bin flash -b

.PHONY: flash_bootloader
flash_bootloader: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> flash_bootloader'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -a -U -w $(DISTDIR)/last.bin bootloader -B

.PHONY: reset
reset: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> reset'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -b

.PHONY: debug
debug: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> debug @localhost:2000'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -w $(DISTDIR)/last.bin flash -b -G

.PHONY: term
term: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> term'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -w $(DISTDIR)/last.bin flash -b -T 9600

.PHONY: unbrick
unbrick: $(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink
	echo ' >> unbrick'
	-$(CH32ROOT)/extern/ch32v003fun/minichlink/minichlink -u

.PHONY: header
header:
	echo ' >> header'
	cd $(CH32ROOT)/device/$(DEVICE) && python $(CH32ROOT)/scripts/genheader.py

