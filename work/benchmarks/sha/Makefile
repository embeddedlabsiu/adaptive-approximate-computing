FILE1 = main.c sha1.c

all: hashes

CC = cgracc

hashes: ${FILE1} Makefile
	$(CC) -static -O3 ${FILE1} -o main

clean:
	rm -rf main output* *.ll CGRAExec m5out *.s
