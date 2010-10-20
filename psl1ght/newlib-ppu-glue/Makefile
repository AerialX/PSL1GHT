.SUFFIXES:
-include ../Makefile.base
-include ../../Makefile.base

TARGET		:=	$(notdir $(CURDIR))
BUILD		:=	build
SOURCE		:=	source
INCLUDE		:=	../include ../newlib/newlib-1.18.0/newlib/libc/include
DATA		:=	data
LIBS		:=	

CFLAGS		:= -g -O2 -Wall -fno-exceptions
ifdef PS3DEV # ooPo's ps3toolchain
CFLAGS		+= -I$(PS3DEV)/ppu/include
endif

ifneq ($(BUILD),$(notdir $(CURDIR)))

export OUTPUT	:=	$(CURDIR)/$(TARGET)
export VPATH	:=	$(foreach dir,$(SOURCE),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))
export BUILDDIR	:=	$(CURDIR)/$(BUILD)
export DEPSDIR	:=	$(BUILDDIR)

CFILES		:= $(foreach dir,$(SOURCE),$(notdir $(wildcard $(dir)/*.c)))
CXXFILES	:= $(foreach dir,$(SOURCE),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:= $(foreach dir,$(SOURCE),$(notdir $(wildcard $(dir)/*.S)))
BINFILES	:= $(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.bin)))

export OFILES	:=	$(CFILES:.c=.o) \
					$(CXXFILES:.cpp=.o) \
					$(SFILES:.S=.o)

export BINFILES	:=	$(BINFILES:.bin=.bin.h)

export INCLUDES	:=	$(foreach dir,$(INCLUDE),-I$(CURDIR)/$(dir)) \
					-I$(CURDIR)/$(BUILD)

.PHONY: $(BUILD) clean

$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

clean:
	@echo Clean...
	@rm -rf $(BUILD) $(OUTPUT).a

else

DEPENDS	:= $(OFILES:.o=.d)

$(OUTPUT).a: $(OFILES)
$(OFILES): $(BINFILES)

-include $(DEPENDS)

endif
