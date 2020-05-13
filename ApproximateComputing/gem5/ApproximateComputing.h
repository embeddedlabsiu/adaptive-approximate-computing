#ifndef __APPROXIMATECOMPUTING_HH__
#define __APPROXIMATECOMPUTING_HH__

namespace ApproximateComputing {

/**
 * @brief This class wraps all of the hardware implementations created by the hardware group.
 * 
 */
class HardwareDescription
{
public:
    
	/**
	 * @brief Enum of the types of adders
	 * 
	 */
	struct AdderTypes
	{
		enum Enum
		{
			StandardAddition = -1,
			Exact = 0,
			ApproximateFiftyPercentPower,
			lpCLibMethod
		};
	};
				
	/**
	 * @brief 
	 * 
	 */
	struct LPCLibraryMethod
	{
		enum Enum
		{
			ZeroApproximation = 0,
			FirstApproximation = 1,
			ThirdApproximation = 3
		};
	};


	/**
	 * @brief Enum of the types of multipliers
	 * 
	 */
	struct MultiplierTypes
	{
		enum Enum
		{
			StandardMultiplier = -1,
			Exact = 0,
			lpCLibMethod,
			ApproximateFirstMlab
		};
	};

	/**
	 * @brief Enum of the types of subtractors
	 * 
	 */
	struct SubtractorTypes
	{
		enum Enum
		{
			StandardSubtractor = -1,
			lpCLibMethod,
		};
	};

	/**
	 * @brief This is a generic structure that contains the relevant values for using approximate computing
	 * 
	 */
	struct LogicUnitDescription
	{
		int approximatedNumberOfBits;
		int approximationType;
		int lpcApproximationMethod;

		LogicUnitDescription()
			: approximatedNumberOfBits( 0 )
			, approximationType( -1 )
			, lpcApproximationMethod( -1 )
		{}
	};

	/**
	 * @brief This structure describes a multiplier. This is done because the multiplier has unique values when using the LP C Lib implementation
	 * of the approximate multiplier. 
	 * 
	 */
	struct MultiplyDescription
	{
		int approximatedNumberOfBits;
		int multiplyMethod;
		int additionMethod;
		int approximationType;

		MultiplyDescription()
			: approximatedNumberOfBits( 0 )
			, multiplyMethod( -1 )
			, additionMethod( -1 )
			, approximationType( -1 )
		{}
	};   
	
	/**
	 * @brief Method that wraps the different kinds of adders. This method will automatically call the appropriate hardware impelementation.
	 * 
	 * @param input_a augend
	 * @param input_b addend
	 * @param approxBits number of bits to approximate. This will only work with the LP C Lib implementation of the addition.
	 * @param adderTypes specific adder to use
	 * @param lpcApproximationMethod LP C Lib approximation method @note this is only used when the LP C Library type is used for the specified
	 * arithmetic operation.
	 * @return int sum
	 */
    static int addition( unsigned int input_a, unsigned int input_b, int approxBits, AdderTypes::Enum adderTypes, LPCLibraryMethod::Enum lpcApproximationMethod );

	/**
	 * @brief Method that wraps the different kinds of multiplication. This method will automatically call the appropriate hardware impelementation.
	 * 
	 * @param input_a Multiplier
	 * @param input_b Multiplicand
	 * @param approxBits number of bits to approximate. This will only work with the LP C Lib implementation of the addition.
	 * @param multMethod Describes the method to multiply. This will only work with the LP C Lib implementation of the addition.
	 * @param additionMethod Describes the method to addition. This will only work with the LP C Lib implementation of the addition.
	 * @param multiplierTypes hardware implementation to use
	 * @return int product
	 */
    static int multiplication( unsigned int input_a, unsigned int input_b, int approxBits, int multMethod, int additionMethod, MultiplierTypes::Enum multiplierTypes );

	/**
	 * @brief Method that wraps the different kinds of subtraction. This method will automatically call the appropriate hardware impelementation.
	 * 
	 * @note There is no subtraction hardware yet.
	 * @param input_a Minuend
	 * @param input_b Subtrahend
	 * @param approxBits number of bits to approximate. This will only work with the LP C Lib implementation of the addition.
	 * @param subtractorTypes hardware implementation to use
	 * @param lpcApproximationMethod LP C Lib approximation method @note this is only used when the LP C Library type is used for the specified
	 * arithmetic operation.
	 * @return int difference
	 */
	static int subtraction( unsigned int input_a, unsigned int input_b, int approxBits, SubtractorTypes::Enum subtractorTypes, LPCLibraryMethod::Enum lpcApproximationMethod );

private:

		/**
		 * @brief The constructors are private to ensure that an instance of this class cannot be created.
		 */
		HardwareDescription();

		HardwareDescription( const HardwareDescription& parser );
};
}

#endif