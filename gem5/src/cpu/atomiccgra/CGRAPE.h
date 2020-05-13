/*
* PE.h
*
* Created on: May 24, 2011
* Author: mahdi
*
* Last edited: 22 May 2017
* Author: Shail Dave
*/

#include "ApproximateComputing.h"
#include "CGRARegisterFile.h"
#include "CGRAInstruction.h"
#include "CGRA_MemoryPort.h"

#ifndef PE_H_
#define PE_H_

class CGRA_RegisterFile;
class CGRA_Instruction;
class LoggingHandler;

class CGRA_PE
{
public:

	/**
	 * @brief This enum defines the approximate hardware types that can be used.
	 * 
	 */
	struct HardwareType
	{
		enum Enum
		{
			Adder,
			Multiplier,
			Subtractor	
		};
	};

	/**
	 * @brief This structure holds the pertinent statistics for PE operations
	 * 
	 */
	struct Statistics
	{
		unsigned int additionsPerformed;
		unsigned int multiplicationsPerformed;
		unsigned int subtractionsPerformed;

		unsigned int andPerformed;
		unsigned int orPerformed;
		unsigned int xorPerformed;
		unsigned int cgraASRPerformed;
		unsigned int noopPerformed;
		unsigned int cgraASLPerformed;
		unsigned int divPerformed;
		unsigned int remPerformed;
		unsigned int lshrPerformed;
		unsigned int eqPerformed;
		unsigned int neqPerformed;
		unsigned int gtPerformed;
		unsigned int ltPerformed;

		Statistics()
			: additionsPerformed( 0 )
			, multiplicationsPerformed( 0 )
			, subtractionsPerformed( 0 )
			, andPerformed( 0 )
			, orPerformed( 0 )
			, xorPerformed( 0 )
			, cgraASRPerformed( 0 )
			, noopPerformed( 0 )
			, cgraASLPerformed( 0 )
			, divPerformed( 0 )
			, remPerformed( 0 )
			, lshrPerformed( 0 )
			, eqPerformed( 0 )
			, neqPerformed( 0 )
			, gtPerformed( 0 )
			, ltPerformed( 0 )
			{}
	};

	CGRA_PE();
	virtual ~CGRA_PE();

	void Fetch(CGRA_Instruction* ins);
	void Decode();
	int Execute();
	void WriteBack();

	int * getOutputPtr();
	int getOutput();

	void SetNeighbours(int* Left, int* Right, int* Up, int* Down);
	void advanceTime();
	void SetController_Reg();
	bool getController_Reg();
	void D_WriteRegfile(int address, int value);
	int GetConfigBoundary();
	void SetConfigBoundary(int config);
	void ClearRegfile();

	void setDataBus(int * data);
	void setAddressBus(uint64_t * addr);
	void setRWStatusBus(int * status);
	void setAlignmentBus(unsigned *alignment);

	void setPENumber( unsigned peNumber );
	unsigned pENumber() const;

	void setLPCLibraryMethod( HardwareType::Enum hardwareType, int lPCLibraryMethod );

	int LPCLibraryMethod( HardwareType::Enum hardwareType ) const;

	/**
	 * @brief getter for the approximated number of bits
	 * @notes This only works on LP C Lib Method
	 * @param hardwareType to get the approximated number of bits
	 * @return int approximated number of bits
	 */
	int approximatedNumberOfBits( HardwareType::Enum hardwareType ) const;

	/**
	 * @brief setter for the approximated number of bits
	 * @notes This only works on LP C Lib Method
	 * @param hardwareType to set the approximated number of bits
	 * @param numberOfBits 
	 */
	void setApproximatedNumberOfBits( HardwareType::Enum hardwareType, const int numberOfBits );

	/**
	 * @brief getter for the approximation type
	 * 
	 * @param hardwareType to get the approximation type 
	 * @return int approximation type
	 */
	int approximationType( HardwareType::Enum hardwareType ) const;

	/**
	 * @brief setter for the approximation type
	 * 
	 * @param hardwareType to set the approximation type 
	 * @param approximationType to be set 
	 */
	void setApproximateType( HardwareType::Enum hardwareType, const int approximationType );

	/**
	 * @brief getter for the addition type
	 * @notes This only works on LP C Lib Method with multiplication
	 * @param hardwareType to get the addition type
	 * @return int addition type
	 */
	int additionType( HardwareType::Enum hardwareType ) const;

	/**
	 * @brief setter for the addition type
	 * @notes This only works on LP C Lib Method with multiplication
	 * @param hardwareType to set the addition type
	 * @param additionType to set
	 */
	void setAdditionType( HardwareType::Enum hardwareType, int additionType );

	/**
	 * @brief getter for the multiplication type
	 * @notes This only works on LP C Lib Method with multiplication
	 * @param hardwareType to set the multiplication type
	 * @return int multiplication type
	 */
	int multiplyType( HardwareType::Enum hardwareType ) const;

	/**
	 * @brief setter for the multiplication type
	 * @notes This only works on LP C Lib Method with multiplication
	 * @param hardwareType to set the multiplication type 
	 * @param multiplyType to set
	 */
	void setMultiplyType( HardwareType::Enum hardwareType, int multiplyType );

	/**
	 * @brief getter for the statistics
	 * 
	 * @return const CGRA_PE::Statistics& 
	 */
	const CGRA_PE::Statistics& statistics() const;

private:
	bool Controller_Reg;

	//----Approximate computing additions----//
	unsigned _peNumber;
	Statistics _statistics;
	ApproximateComputing::HardwareDescription::LogicUnitDescription _adderDescription;
	ApproximateComputing::HardwareDescription::LogicUnitDescription _subtractorDescription;
	ApproximateComputing::HardwareDescription::MultiplyDescription _multiplierDescription;
	LoggingHandler* _logger;
	//--------------------------------------//

	int Input1;
	int Input2;
	//Support for Predicated Operations or P-type instructions
	int InputP;
	int Output;
	unsigned config_boundary;

	CGRA_RegisterFile RegFile;
	CGRA_Instruction* ins;

	int *leftIn;
	int *rightIn;
	int *upIn;
	int *downIn;

	int* BsStatus;
	int* dataBs;
	uint64_t* addressBs;
	unsigned* alignmentBs;
};

#endif /* PE_H_ */
