-include Makefile.base

CFILES		:= $(wildcard stub/*.c)
SFILES		:= $(wildcard stub/*.S)

STUBS		:= $(SFILES:.S=.o) $(CFILES:.c=.o)

all: $(STUBS)
	@ppu-ld -r $(STUBS) -o stub/crt1.o
	@make -C tools/raw2h --no-print-directory
	@make -f Makefile.lib --no-print-directory
	@make -C libc-glue-ppu --no-print-directory

clean:
	rm -f $(STUBS) stub/crt1.o stub.a
	@make -C tools/raw2h clean --no-print-directory
	@make -f Makefile.lib clean --no-print-directory
	@make -C libc-glue-ppu clean --no-print-directory

install: all
	@mkdir -p $(PSL1GHT)/include $(PSL1GHT)/lib $(PSL1GHT)/bin
	@cp linker.x libpsl1ght.a libc-glue-ppu/libc-glue-ppu.a stub/crt1.o $(PSL1GHT)/lib/
	@cp -r include $(PSL1GHT)/
	@cp Makefile.base $(PSL1GHT)/
	@cp tools/raw2h/raw2h $(PSL1GHT)/bin/
	@cp tools/make_fself/make_fself.py $(PSL1GHT)/bin/
	@cp tools/make_fself/Struct.py $(PSL1GHT)/bin/

%.o: %.c
	$(CC) -Iinclude -c $< -o $@

%.o: %.S
	$(CC) -Iinclude -c $< -o $@

.PHONY: all clean install
