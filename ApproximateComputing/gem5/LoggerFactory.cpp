#include "LoggerFactory.h"

#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>

#include "LoggingHandler.h"

namespace ApproximateComputing {

LoggingHandler* LoggerFactory::buildLogger( const std::string& filename, bool deleteFile )
{
	if ( deleteFile )
	{
		remove( filename.c_str() );
	}
	return new LoggingHandler( filename );
}

} // namespace ApproximateComputing