BASE = ../../../../CppProjects/llvm_build/Debug+Asserts
TARGET = patricia
CLANG = $(BASE)/bin/clang
CLANGFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass

%.bc: %.c
	$(CLANG) $(CLANGFLAGS) -o $@ $<

patricia_combined.bc: patricia.bc patricia_test.bc
	$(LINK) -o $@ *.bc

pass: patricia_combined.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

patricia: patricia.c patricia_test.c
	gcc -static patricia.c patricia_test.c -O3 -o patricia

clean:
	rm -rf patricia output* *.bc
