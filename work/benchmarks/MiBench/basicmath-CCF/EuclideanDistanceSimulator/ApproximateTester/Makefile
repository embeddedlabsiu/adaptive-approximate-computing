CC=g++
LINKERFLAGS = -Wall -std=c++11 
SOURCES := $(wildcard *.cpp)

ApproximateComputing: ${SOURCES}
		$(CC) ${LINKERFLAGS} ${SOURCES} -o Test.run -lm

all: Test
	
clean:
	rm -f *.o Test.run
