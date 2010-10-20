-include Makefile.base

CFILES		:= $(wildcard stub/*.c)
SFILES		:= $(wildcard stub/*.S)

STUBS		:= $(SFILES:.S=.o) $(CFILES:.c=.o)

all: $(STUBS)
	@make -C tools/raw2h --no-print-directory
	@make -f Makefile.lib --no-print-directory
	@make -C newlib-ppu-glue --no-print-directory
	@make -C newlib --no-print-directory

clean:
	rm -f $(STUBS) stub.a
	@make -C tools/raw2h clean --no-print-directory
	@make -f Makefile.lib clean --no-print-directory
	@make -C newlib-ppu-glue clean --no-print-directory
	@make -C newlib clean --no-print-directory

install: all
	@mkdir -p $(PSL1GHT)/include $(PSL1GHT)/lib $(PSL1GHT)/bin
	@cp libpsl1ght.a newlib-ppu-glue/newlib-ppu-glue.a $(PSL1GHT)/lib/
	@cp newlib-ppu-glue/newlib-ppu-glue.a $(PSL1GHT)/lib/libc-glue.a
	@cp linker.x stub/crt0.o stub/crt1.o $(PSL1GHT)/lib/
	@cp -r include $(PSL1GHT)/
	@cp Makefile.base $(PSL1GHT)/
	@cp tools/raw2h/raw2h $(PSL1GHT)/bin/
	@make -C newlib install --no-print-directory

%.o: %.c
	$(CC) -Iinclude -c $< -o $@

%.o: %.S
	$(CC) -x assembler-with-cpp -Iinclude -c $< -o $@

