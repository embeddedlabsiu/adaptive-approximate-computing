#!/usr/bin/env python

import argparse
import pandas as pd
import sys
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.collections import LineCollection
from matplotlib.colors import colorConverter
# from matplotlib.backends.backend_pdf import PdfPages
import numpy as np
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
# matplotlib.use('PNG')

def parseCommandLineArgument():
    parser = argparse.ArgumentParser( description="Tester" )

    parser.add_argument('--file', '-f', action="store", help="file" )
    # parser.add_argument('--out', '-', action="store", help="file" )

    args = parser.parse_args()

    return args

def convertToExcel( filename ):
    newFileName = filename + ".xlsx"
    print filename
    dataFrame = pd.read_csv( filename )
    excelWriter = pd.ExcelWriter( newFileName )
    dataFrame.to_excel( excelWriter, newFileName )
    excelWriter.save()

    return filename 

def cc(arg):
    return colorConverter.to_rgba(arg, alpha=0.6)

if __name__ == '__main__':
    arguments = parseCommandLineArgument()
    # filename = convertToExcel( arguments.file )
    ws_data=pd.read_excel( arguments.file, sheet_name=arguments.file )
    values = [[0 for x in xrange(len(ws_data.X ) )] for y in xrange(len( ws_data.X) ) ]
    # values = []
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    verts = []
    zeroApprox = []

    zs = [ 2, 4, 6, 8, 16 ]
 
    
    # print values
    for x in zs:    
        if x == 16:
            ys = np.array(ws_data.Zero)
        elif x == 2:
            ys = np.array(ws_data.First)
        elif x == 4:
            ys = np.array(ws_data.Second)
        elif x ==6:
            ys = np.array(ws_data.Third)
        elif x ==8:
            ys = np.array(ws_data.Fourth)

        ys[0], ys[-1] = 0.0, 0.0
        verts.append( list( zip( np.array(ws_data.X), ys ) ) )
    
    poly = LineCollection(verts, facecolors=[cc('r'), cc('g'), cc('b'), cc('y'), cc('c')  ])
    poly.set_alpha(0.7)
    ax.add_collection3d(poly, zs=zs, zdir='y')

    ax.set_xlabel('Input')
    ax.set_xlim3d(0, len( ws_data.X ) )
    ax.set_ylabel('Error Tolerance (%)')
    ax.set_ylim3d(0, 16)
    ax.set_zlabel('Percent Error')
    ax.set_zlim3d(0, 20)
    # plt.savefig(arguments.out)
    plt.show()
    