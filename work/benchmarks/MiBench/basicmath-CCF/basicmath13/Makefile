FILE1 = basicmath_small.c isqrt.c ../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/CGRA.c ../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/DynamicCGRAControl.c ../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/ArithmeticLogicUnitList.c ../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/LinkedList.c ../../../../../ApproximateComputing/DynamicRuntimeCGRAControl/ArithmeticLogicUnit.c
FILE2 = basicmath_large.c   rad2deg.c  cubic.c   isqrt.c

all: basicmath_small 


CC = ../../../../../scripts/CGRALib/cgracc
LIB = -lm
basicmath_small: ${FILE1} Makefile
	$(CC) -static -O3 ${FILE1} -o basicmath_small $(LIB)

clean:
	rm -rf basicmath_small basicmath_large *.ll CGRAExec m5out *.s
