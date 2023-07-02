include device/$(DEVICE)/makefile.mk
TARGET				:= test_application
BUILDLOC			:= $(BUILDDIR)/$(DIR)
DISTLOC				:= $(DISTDIR)/$(DIR)

# SOURCE FILES HERE. $(DIR) is root of project tree
SRCFILES			+= $(DIR)/main.c

OBJFILES			:= $(SRCFILES:%.c=$(BUILDLOC)/%.c.o)
DEPFILES			:= $(SRCFILES:%.c=$(BUILDLOC)/%.c.d)

CC						:= $(PREFIX)-gcc
LD						:= $(PREFIX)-gcc
AS						:= $(PREFIX)-gcc
OBJCOPY 			:= $(PREFIX)-objcopy
OBJDUMP 			:= $(PREFIX)-objdump
SIZE     			:= $(PREFIX)-size

CFLAGS				+= -I.
LDFLAGS				+= -T device/$(DEVICE)/linker.ld -lgcc

# Add DEPFILE dependencies
-include $(DEPFILES)

.PHONY: $(TARGET)
$(TARGET): $(DISTLOC)/$(TARGET).elf

$(DISTLOC)/$(TARGET).elf: $(OBJFILES)
	echo 'LD ' $@
	echo $(SRCNAMES)
	-mkdir -p $(shell dirname $@)
	$(LD) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJFILES) $(CC_LIBS)
	$(SIZE) $@
	$(OBJDUMP) -S $@ > $@.lst
	$(OBJDUMP) -t $@ > $@.map
	$(OBJCOPY) -O binary $@ $@.bin
	$(OBJCOPY) -O ihex $@ $@.hex

$(OBJFILES): $(BUILDLOC)/%.c.o: %.c
	echo 'CC ' $@
	-mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -MD -o $@ -c $<