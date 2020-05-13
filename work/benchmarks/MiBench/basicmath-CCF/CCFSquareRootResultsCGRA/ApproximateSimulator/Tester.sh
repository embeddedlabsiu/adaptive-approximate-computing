#!/bin/bash

CURRENTDATE=`date +"%m-%d %T"`
directory=$(pwd)"/Results/";

make

./Simulator.run -n 4 -b $1 -e $2 -s $3 -t $4 > "${directory}${CURRENTDATE}_4_.csv"
./Simulator.run -n 8 -b $1 -e $2 -s $3 -t $4 > "${directory}${CURRENTDATE}_8_.csv"
./Simulator.run -n 12 -b $1 -e $2 -s $3 -t $4 > "${directory}${CURRENTDATE}_12_.csv"
./Simulator.run -n 16 -b $1 -e $2 -s $3 -t $4 > "${directory}${CURRENTDATE}_16_.csv"