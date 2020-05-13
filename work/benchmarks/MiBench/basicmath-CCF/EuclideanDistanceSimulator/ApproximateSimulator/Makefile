CC=g++
LINKERFLAGS = -Wall -std=c++11 
SOURCES := $(wildcard *.cpp)

ApproximateComputing: ${SOURCES}
		$(CC) ${LINKERFLAGS} ${SOURCES} -o Simulator.run -lm

all: Test
	
clean:
	rm -f *.o Simulator.run
