.SILENT:
DEVICE 				?= ch32v203
PART					?= g6
DEBUG					?=
BUILDDIR_BASE	:= $(PWD)/build
DISTDIR_BASE	:= $(PWD)/dist

ifeq "$(DEBUG)" ""
	BUILDDIR		:= $(BUILDDIR_BASE)/release
	DISTDIR			:= $(DISTDIR_BASE)/release
else
	CFLAGS 			+= -g
	BUILDDIR		:= $(BUILDDIR_BASE)/debug
	DISTDIR			:= $(DISTDIR_BASE)/debug
endif

.PHONY: all clean flash flash_bootloader

all: test_application

clean:
	echo ' >> clean'
	-rm -rf $(BUILDDIR_BASE)

DIR = test_application
include $(DIR)/Makefile

flash:
	echo ' >> flash'
	-extern/ch32v003fun/minichlink/minichlink -w $(DISTDIR)/last.bin flash -b

flash_bootloader:
	echo ' >> flash_bootloader'
	-extern/ch32v003fun/minichlink/minichlink -w $(DISTDIR)/last.bin flash -b
