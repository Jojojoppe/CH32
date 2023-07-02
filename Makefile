.SILENT:
DEVICE 				:= ch32v003
DEBUG					:= 1
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

.PHONY: all clean

all: test_application

clean:
	echo 'CLEAN'
	-rm -rf $(BUILDDIR_BASE)

DIR = test_application
include $(DIR)/Makefile

