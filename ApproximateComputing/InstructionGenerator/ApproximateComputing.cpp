#include "ApproximateComputing.h"

namespace ApproximateComputing {

void PELogger::logArithmeticPEs( std::ofstream& fileToLog, const ArithmeticPEs& peToLog )
{
	if ( peToLog.size() == 0 )
	{
		fileToLog  << "!" << "\n";
	}

	for ( ArithmeticPEs::const_iterator it = peToLog.begin(); it < peToLog.end(); ++it )
	{
		fileToLog << *it;
		if ( it + 1 == peToLog.end() ) 
		{
			fileToLog  << "\n";
		}
		else
		{
			fileToLog  << ",";
		}
	}	
}

} // namespace ApproximateComputing