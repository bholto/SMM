BASE = ../../../../CppProjects/llvm_build/Debug+Asserts
TARGET = rijndael
CLANG = $(BASE)/bin/clang
CLANGFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass

%.bc: %.c
	$(CLANG) $(CLANGFLAGS) -o $@ $<

crc.bc: crc_32.bc
	$(LINK) -o $@ *.bc

pass: crc.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

crc: crc_32.c Makefile
	gcc -static crc_32.c -O3 -o crc 

clean:
	rm -rf crc output*
