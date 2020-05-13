#include "ArithmeticLogicUnit.h"

#include "CGRADefinitions.h"

void initLogicUnitDescription( LogicUnitDescription* logicUnitDescription )
{
	logicUnitDescription->isUsed = false;
	logicUnitDescription->approximatedNumberOfBits = -1;
	logicUnitDescription->approximationType = -1;
	logicUnitDescription->lpcApproximationMethod = 0;
}

void initMultiplierDescription( MultiplierDescription* multiplierDescription )
{
	multiplierDescription->isUsed = false;
	multiplierDescription->approximatedNumberOfBits = -1;
	multiplierDescription->approximationType = -1;
	multiplierDescription->multiplyMethod = -1;
	multiplierDescription->additionMethod = -1;
}

void initArithmeticPEDescription( ArithmeticPEDescription* arithmeticPEDescription )
{
	initLogicUnitDescription( &arithmeticPEDescription->adder );
	initMultiplierDescription( &arithmeticPEDescription->multiplier );
	initLogicUnitDescription( &arithmeticPEDescription->subtractor );
}

void printArithmeticPEDescription( const ArithmeticPEDescription* const arithmeticPEDescription, char* buffer, int* bufferPosition )
{
	*bufferPosition += snprintf( buffer + *bufferPosition, BufferSize - *bufferPosition, "%i,%i,%i:%i,%i,%i:%i,%i,%i,%i\n"
									, arithmeticPEDescription->adder.approximatedNumberOfBits
									, arithmeticPEDescription->adder.approximationType
									, arithmeticPEDescription->adder.lpcApproximationMethod
									, arithmeticPEDescription->subtractor.approximatedNumberOfBits
									, arithmeticPEDescription->subtractor.approximationType
									, arithmeticPEDescription->subtractor.lpcApproximationMethod
									, arithmeticPEDescription->multiplier.approximatedNumberOfBits
									, arithmeticPEDescription->multiplier.approximationType
									, arithmeticPEDescription->multiplier.additionMethod
									, arithmeticPEDescription->multiplier.multiplyMethod );
}