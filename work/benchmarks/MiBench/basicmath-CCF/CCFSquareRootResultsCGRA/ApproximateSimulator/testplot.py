#!/usr/bin/env python

import csv
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import
import argparse
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import cm
import pandas as pd


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


if __name__ == '__main__':
    arguments = parseCommandLineArgument()
    # filename = convertToExcel( arguments.file )

    ws_data=pd.read_excel( arguments.file, sheet_name=arguments.file )#, nrows=arguments.loopSize * arguments.loopSize )
    # ws_data=pd.read_csv( arguments.file )#, nrows=arguments.loopSize * arguments.loopSize )
    # print arguments.loopSize, arguments.startingApproximateBits
    # Replace space from column names, otherwise pandas acts up
    #cols = ws_data.columns
    #cols = cols.map(lambda x: x.replace(' ', '_') if isinstance(x, (str, unicode)) else x)
    #ws_data.columns = cols

    xtick_rot=90
    xticks_font_size=10
    yticks_font_size=10
    x_axis_font_size=10
    y_axis_font_size=10
    annot_font_size=19
    legend_font_size=9
    fig = plt.figure()
    ax = fig.add_subplot(111)
    # ax = plt.add_subplot(111, projection='3d')

    # ax.plot(np.array(ws_data.X), np.array(ws_data.Y),np.array(ws_data.Percent_Error), linewidth=1,zorder=3,label='memory-intensive',color='blue',marker='.',markersize=6)
    ax.plot(np.array(ws_data.X), np.array(ws_data.Zero_Error),linewidth=1,label='Zero',color='blue',marker='.')
    ax.plot(np.array(ws_data.X), np.array(ws_data.First_Error),linewidth=1,label='First',color='red',marker='.')
    ax.plot(np.array(ws_data.X), np.array(ws_data.Third_Error),linewidth=1,  label='Third',color='black',marker='.')
    plt.legend(loc='upper left')

    ax.set_xlabel('Square Root Value', fontsize=y_axis_font_size)
    ax.set_ylabel('Error', fontsize=x_axis_font_size)
    # ax.set_zlabel('Percent Error',fontsize=x_axis_font_size)

    handles, labels = plt.gca().get_legend_handles_labels()
    order = [0,1,2]
    # fig.legend([handles[idx] for idx in order],[labels[idx] for idx in order],ncol=3,loc='upper center',bbox_to_anchor=(0.55, 0.9),fontsize=legend_font_size,frameon=False,facecolor='white')	

    plt.show()
    