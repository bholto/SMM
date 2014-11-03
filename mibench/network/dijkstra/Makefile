BASE = ../../../llvm-3.6-build/Release+Asserts
TARGET = dijkstra
CLANG = $(BASE)/bin/clang
CLANGFLAGS = -emit-llvm -S
LINK = $(BASE)/bin/llvm-link
OPT = $(BASE)/bin/opt
OPTFLAGS = -load
GCCFG = $(BASE)/lib/LLVMGccfg.dylib
GCCFGFLAGS = -GccfgPass

all:  dijkstra_large dijkstra_small

pass: dijkstra_large.bc
	$(OPT) $(OPTFLAGS) $(GCCFG) $(GCCFGFLAGS) < $< > /dev/null

dijkstra_large.bc: dijkstra_large.c
	$(CLANG) $(CLANGFLAGS) -o $@ $<

$(TARGET)_large: dijkstra_large.c Makefile
	gcc -static dijkstra_large.c -O3 -o dijkstra_large

$(TARGET)_small: dijkstra_small.c Makefile
	gcc -static dijkstra_small.c -O3 -o dijkstra_small 

clean:
	rm -rf dijkstra_large dijkstra_small output* *.bc
