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
matplotlib.use('PDF')

def parseCommandLineArgument():
    parser = argparse.ArgumentParser( description="Tester" )

    parser.add_argument('--file', '-f', action="store", help="file" )
    parser.add_argument('--out', '-o', action="store", help="out file" )

    args = parser.parse_args()

    return args


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

    zs = [ 0, 1, 3 ]

    
    for x in zs:    
        if x == 0:
            ys = np.array(ws_data.Zero_Error)
        elif x == 1:
            ys = np.array(ws_data.First_Error)
        elif x ==3:
            ys = np.array(ws_data.Third_Error)

        ys[0], ys[-1] = 0.0, 0.0
        verts.append( list( zip( np.array(ws_data.X), ys ) ) )

    poly = LineCollection(verts, facecolors=[cc('r'), cc('g'), cc('b') ])
    poly.set_alpha(0.7)
    ax.add_collection3d(poly, zs=zs, zdir='y')

    ax.set_xlabel('Input')
    ax.set_xlim3d(0, len( ws_data.X ) )
    ax.set_ylabel('Approximation Type')
    ax.set_ylim3d(-1, 4)
    ax.set_zlabel('Percent Error')
    ax.set_zlim3d(0, 100)
  

    # plt.savefig(arguments.out)
    plt.show()
  