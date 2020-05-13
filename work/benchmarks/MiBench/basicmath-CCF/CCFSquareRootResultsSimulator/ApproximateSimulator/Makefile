CC=g++
LINKERFLAGS = -Wall -std=c++11 
SOURCES := $(wildcard *.cpp)

all: ApproximateComputing
	mkdir -p ./Results

ApproximateComputing: ${SOURCES}
		$(CC) ${LINKERFLAGS} ${SOURCES} -o Simulator.run -lm
	
clean:
	rm -f *.o Simulator.run
