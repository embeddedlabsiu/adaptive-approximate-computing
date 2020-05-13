#!/bin/bash

CURRENTDATE=`date +"%m-%d %T"`
directory=$(pwd)"/Results/";

make clean
make
mkdir -p Results/

#./Simulator.run -n $1 -b 1 -e 100 -s 1 -t -1 > "${directory}${CURRENTDATE}.csv"
./Simulator.run -n 4 -b 1 -e $1 -s 1 -t $2 > "${directory}${CURRENTDATE}_4_.csv"
./Simulator.run -n 8 -b 1 -e $1 -s 1 -t $2 > "${directory}${CURRENTDATE}_8_.csv"
./Simulator.run -n 12 -b 1 -e $1 -s 1 -t $2 > "${directory}${CURRENTDATE}_12_.csv"
./Simulator.run -n 16 -b 1 -e $1 -s 1 -t $2 > "${directory}${CURRENTDATE}_16_.csv"