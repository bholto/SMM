BASE = ../../../../CppProjects/llvm_build/Debug+Asserts
TARGET = rijndael
CC = $(BASE)/bin/clang
CFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass
    
%.bc: %.c
	$(CC) $(CFLAGS) -o $@ $<

rijndael.bc: aesxam.bc aes.bc
	$(LINK) -o $@ *.bc

pass: rijndael.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

rijndael: aes.c aes.h aestab.h aesxam.c Makefile
	gcc -static -O3 -o rijndael aes.c aesxam.c

clean:
	rm -rf rijndael output* *.bc
