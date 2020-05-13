FILE1 = basicmath_small.c isqrt.c CGRA.c DynamicCGRAControl.c ArithmeticLogicUnitList.c LinkedList.c ArithmeticLogicUnit.c

all: basicmath_small 


CC = ../../../../../../scripts/CGRALib/cgracc
LIB = -lm
basicmath_small: ${FILE1} Makefile
	$(CC) -static -O3 ${FILE1} -o basicmath_small $(LIB)

clean:
	rm -rf basicmath_small basicmath_large *.ll CGRAExec m5out *.s
