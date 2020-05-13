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

def parseCommandLineArgument():
    parser = argparse.ArgumentParser( description="Tester" )

    parser.add_argument('--file', '-f', action="store", help="file" )

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

    # print input
    # delta = time_index[1] - time_index[0]
    # verts = []
    zs = [ 0, 1, 3 ]

    # for z in zs:
    #     ys = ipc_values[z]
    #     ys[0], ys[-1] = 0.0, 0.0
    #     verts.append(list(zip(time_index, ys)))
    # print np.array(ws_data.Third_Error)
    
    # print values
    for x in zs:    
        if x == 0:
            ys = np.array(ws_data.Zero_Error)
        elif x == 1:
            ys = np.array(ws_data.First_Error)
        elif x ==3:
            ys = np.array(ws_data.Third_Error)

        ys[0], ys[-1] = 0.0, 0.0
        verts.append( list( zip( np.array(ws_data.X), ys ) ) )
    # if number_cores == 4:
    #     poly = PolyCollection(verts, facecolors=[cc('r'), cc('g'), cc('b'), cc('y')])
    # elif number_cores == 8:
    #     poly = PolyCollection(verts,
    #                           facecolors=[cc('r'), cc('g'), cc('b'), cc('y'), cc('c'), cc('m'), cc('k'), cc('#cc6600')])
    # elif number_cores == 16:
    #     poly = PolyCollection(verts,
    #                           facecolors=[cc('r'), cc('g'), cc('b'), cc('y'), cc('c'), cc('m'), cc('k'), cc('#cc6600'),
    #                                       cc('#333399'), cc('#cc00ff'), cc('#00ffcc'), cc('#666600'), cc('#5c8a8a'),
    #                                       cc('#b3b300'), cc('#b3b3e6'), cc('#ff8080')])
    # else:
    #     print "Not valid number of cores => exit. Pick a value of 4, 8 or 16"
    #     sys.exit()
    # print values
    # poly = PolyCollection(verts, facecolors=[cc('r'), cc('g'), cc('b') ])
    poly = LineCollection(verts, facecolors=[cc('r'), cc('g'), cc('b') ])
    poly.set_alpha(0.7)
    ax.add_collection3d(poly, zs=zs, zdir='y')

    ax.set_xlabel('Input')
    ax.set_xlim3d(0, len( ws_data.X ) )
    ax.set_ylabel('Approximation Type')
    ax.set_ylim3d(-1, 4)
    ax.set_zlabel('Percent Error')
    ax.set_zlim3d(0, 100)
    #ax.set_xlabel('Time (ms)')
   # ax.set_xlim3d(0, time_index[number_samples - 1] + 2 * delta)
    #ax.set_ylabel('Core Number')
    #ax.set_ylim3d(-1, number_cores)
    #y_labels = [""]
    #y_labels.extend("{}".format(x) for x in xrange(0, number_cores))
    #y_labels.append("")
    #ax.set_yticklabels(y_labels)
    #ax.set_zlabel('IPC')
    #ax.set_zlim3d(0, np.amax(ipc_values))

    #plot = PdfPages(out_file)
    #plot.savefig()
    #plot.close()
    # plt.savefig(out_file)
    plt.show()
    # fig = plt.figure()
    # ax = fig.add_subplot(121, projection='3d')
    # ws_data=pd.read_excel( arguments.file, sheet_name=arguments.file )#, nrows=arguments.loopSize * arguments.loopSize )
    # ax.bar3d( np.array(ws_data.X), np.array(ws_data.Zero_Error), shade=True)
    
    # # ws_data=pd.read_csv( arguments.file )#, nrows=arguments.loopSize * arguments.loopSize )
    # # print arguments.loopSize, arguments.startingApproximateBits
    # # Replace space from column names, otherwise pandas acts up
    # #cols = ws_data.columns
    # #cols = cols.map(lambda x: x.replace(' ', '_') if isinstance(x, (str, unicode)) else x)
    # #ws_data.columns = cols

    # xtick_rot=90
    # xticks_font_size=10
    # yticks_font_size=10
    # x_axis_font_size=10
    # y_axis_font_size=10
    # annot_font_size=19
    # legend_font_size=9
    # fig = plt.figure()
    # ax = fig.add_subplot(111)
    # # ax = plt.add_subplot(111, projection='3d')

    # # ax.plot(np.array(ws_data.X), np.array(ws_data.Y),np.array(ws_data.Percent_Error), linewidth=1,zorder=3,label='memory-intensive',color='blue',marker='.',markersize=6)
    # ax.plot(np.array(ws_data.X), np.array(ws_data.Zero_Error),linewidth=1,label='Zero Approx.',color='blue',marker='.')
    # ax.plot(np.array(ws_data.X), np.array(ws_data.First_Error),linewidth=1,label='First Approx.',color='red',marker='.')
    # ax.plot(np.array(ws_data.X), np.array(ws_data.Third_Error),linewidth=1,  label='Third Approx.',color='black',marker='.')
    # plt.legend(loc='upper left')

    # ax.set_xlabel('Basic Math 13', fontsize=y_axis_font_size)
    # ax.set_ylabel('Error', fontsize=x_axis_font_size)
    # # ax.set_zlabel('Percent Error',fontsize=x_axis_font_size)

    # handles, labels = plt.gca().get_legend_handles_labels()
    # order = [0,1,2]
    # # fig.legend([handles[idx] for idx in order],[labels[idx] for idx in order],ncol=3,loc='upper center',bbox_to_anchor=(0.55, 0.9),fontsize=legend_font_size,frameon=False,facecolor='white')	

    # plt.show()
    