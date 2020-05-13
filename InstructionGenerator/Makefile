FILE1 = insgen.cpp ApproximateComputing.cpp

all: InstructionGenerator 

Compiler = g++

InstructionGenerator: ${FILE1} Makefile
	$(Compiler) -static -O3 ${FILE1} -o insgen

clean:
	rm -rf insgen
