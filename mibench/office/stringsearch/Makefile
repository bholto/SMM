FILE1 = bmhasrch.c  bmhisrch.c  bmhsrch.c  pbmsrch_small.c 
FILE2 = bmhasrch.c  bmhisrch.c  bmhsrch.c  pbmsrch_large.c 
FILE3 = bmhasrch.bc  bmhisrch.bc  bmhsrch.bc  pbmsrch_large.bc 

BASE = ../../../../CppProjects/llvm_build/Debug+Asserts
TARGET = stringsearch
CLANG = $(BASE)/bin/clang
CLANGFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass

%.bc: %.c
	$(CLANG) $(CLANGFLAGS) -o $@ $<

$(TARGET)_combined.bc: $(FILE3)
	$(LINK) -o $@ $(FILE3)

pass: $(TARGET)_combined.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

all: search_small search_large

search_small: ${FILE1} Makefile
	gcc -static ${FILE1} -O3 -o search_small

search_large: ${FILE2} Makefile
	gcc -static ${FILE2} -O3 -o search_large

clean:
	rm -rf search_small search_large output* *.bc
