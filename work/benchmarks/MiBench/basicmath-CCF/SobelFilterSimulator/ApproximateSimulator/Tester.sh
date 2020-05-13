#!/bin/bash

CURRENTDATE=`date +"%m-%d %T"`
directory=$(pwd)"/Results/";

make clean
make
mkdir -p Results/

./Simulator.run -n 4 -t $1 > "${directory}${CURRENTDATE}_4_${1}_.csv"
convert -size 100x100 -depth 8 img_out.gray "${CURRENTDATE}_img_4_${1}_out.png"

./Simulator.run -n 8 -t $1 > "${directory}${CURRENTDATE}_8_${1}_.csv"
convert -size 100x100 -depth 8 img_out.gray "${CURRENTDATE}_img_8_${1}_out.png"

./Simulator.run -n 12 -t $1 > "${directory}${CURRENTDATE}_12_${1}_.csv"
convert -size 100x100 -depth 8 img_out.gray "${CURRENTDATE}_img_12_${1}_out.png"

./Simulator.run -n 16 -t $1 > "${directory}${CURRENTDATE}_16_${1}_.csv"
convert -size 100x100 -depth 8 img_out.gray "${CURRENTDATE}_img_16_${1}_out.png"
