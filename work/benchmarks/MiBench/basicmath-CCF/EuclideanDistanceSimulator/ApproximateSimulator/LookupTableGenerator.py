#!/usr/bin/env python

import argparse
import numpy as np
import pandas as pd

intInclude = '#include <stdint.h>' + '\n\n'
arrayDeclaration = 'int8_t lookupTable[] = { '
headerEnd = '#endif'


def parseCommandLineArgument():
    parser = argparse.ArgumentParser( description="Tester" )

    parser.add_argument('--file', '-f', action="store", help="file" )
    parser.add_argument('--outputDirectory', '-o', action="store", help="file" )

    args = parser.parse_args()

    return args


if __name__ == '__main__':
    arguments = parseCommandLineArgument()
    outputArray = []
    # filename = convertToExcel( arguments.file )

    csvData = pd.read_csv( arguments.file, names=[ 'N', 'X1', 'Y1', 'X2', 'Y2', 'Actual', 'Zero_Error', 'First_Error', 'Third_Error' ] )
    counter = 0

    outputFileName = 'ApproximateBitsEquals' + csvData.values[ 1 ][ 0 ] + 'LookupTable.h'
    headerGuard = '#ifndef ' + outputFileName.upper() + '\n' + '#define ' + outputFileName.upper()
    headerGuard = headerGuard.replace( ".", "_" ) + '\n\n'
    outputFileName = arguments.outputDirectory + outputFileName 

    for row in csvData.values:
        counter += 1
        if ( counter == 1 ):
            continue
        zero, first, third = float( row[ 6 ] ), float( row[ 7 ] ), float( row[ 8 ] )
        minimum = min( zero, first, third )
       
        if ( minimum == third ):
            outputArray.append( [ 3, int( third ) ] )
        elif ( minimum == first ):
            outputArray.append( [ 1, int( first ) ] )
        elif ( minimum == zero ):
            outputArray.append( [ 0, int( zero ) ] )
  
    arraySize = len( outputArray )
    arrayDeclaration = 'int8_t lookupTable' + csvData.values[ 1 ][ 0 ] + '[' + str( arraySize ) + ']''[2] = { '

    file = open( outputFileName, 'w+')

    file.write( headerGuard )
    file.write( intInclude )
    
    # file.write( 'uint32_t arraySize = ' + str( arraySize ) + ';\n\n' )
    file.write( arrayDeclaration )
    
    counter = 0
    for i in outputArray:
        string = str ( i )
        string = string.replace( "[", "{" )
        string = string.replace( "]", "}" )

        if ( counter == arraySize - 1 ):
            file.write( string )
        else:
            file.write( string + ', ' )    
        counter += 1

    file.write( ' };\n\n')
    file.write( headerEnd )
    file.close()



    