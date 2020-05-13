FILE1 = bench.c

all: bench
#basicmath_large

CC = cgracc #gcc
bench: ${FILE1} Makefile
	$(CC) -static -O3 ${FILE1} -o bench

clean:
	rm -rf bench output* *.ll CGRAExec m5out *.s
