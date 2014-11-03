# By default, the code is compiled for a "big endian" machine.
# To compile on a "little endian" machine set the LITTLE_ENDIAN flag.
# To make smaller object code, but run a little slower, don't use UNROLL_LOOPS.
# To use NIST's modified SHA of 7/11/94, define USE_MODIFIED_SHA

CC = gcc
CFLAGS = -O3 -Wall
BASE = ../../../../CppProjects/llvm_build/Debug+Asserts
CLANG = $(BASE)/bin/clang
CLANGFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass

%.bc: %.c
	$(CLANG) $(CLANGFLAGS) -o $@ $<

sha_combined.bc: sha_driver.bc sha.bc
	$(LINK) -o $@ *.bc

pass: sha_combined.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

sha:	sha_driver.o sha.o
	$(CC) -o $@ sha_driver.o sha.o
	strip $@

clean:
	rm -rf *.o sha output* *.bc
