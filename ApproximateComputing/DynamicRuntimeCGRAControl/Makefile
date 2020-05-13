CC=gcc
LINKERFLAGS = -Wall -std=c99
SOURCES := $(wildcard *.c)

ApproximateComputing: ${SOURCES}
		$(CC) ${LINKERFLAGS} ${SOURCES} -o ApproximateComputing.run

all: ApproximateComputing
	
clean:
	rm -f *.o ApproximateComputing.run
