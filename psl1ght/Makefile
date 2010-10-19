include Makefile.base

STUBS	:=	stub/crt0.o stub/crt1.o

all: $(STUBS)

clean:
	rm -f $(STUBS)

stub/crt0.o: stub/crt0.S
stub/crt1.o: stub/crt1.c

%.o: %.c
	$(CC) -c $< -o $@

%.o: %.S
	$(CC) -c $< -o $@
