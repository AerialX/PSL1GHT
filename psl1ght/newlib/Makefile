ifeq ($(strip $(PSL1GHT)),)
$(error "PSL1GHT must be set in the environment.")
endif

all:
	@./newlib.sh
	@make -C newlib-ppu
	@#make -C newlib-spu

clean:
	@echo Cleaning up newlib...
	@rm -rf newlib-1.18.0 newlib-ppu newlib-spu

install: all
	@make -C newlib-ppu install
	@rm -rf $(PSL1GHT)/newlib/ppc64/lib/32
	@#make -C newlib-spu install

uninstall:
	@rm -rf $(PSL1GHT)/newlib
