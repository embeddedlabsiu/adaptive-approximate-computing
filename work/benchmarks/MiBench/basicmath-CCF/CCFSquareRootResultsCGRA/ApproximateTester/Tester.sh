#!/bin/bash
CURRENTDATE=`date +"%m-%d %T"`
FileName="${CURRENTDATE}"

./Test.run -n 4 -t 1 -e $1 -s $2 > "${FileName}_4_.csv";
./Test.run -n 8 -t 1 -e $1 -s $2 > "${FileName}_8_.csv";
./Test.run -n 12 -t 1 -e $1 -s $2 > "${FileName}_12_.csv";
./Test.run -n 16 -t 1 -e $1 -s $2 > "${FileName}_16_.csv";

../ApproximateSimulator/LookupTableGenerator.py -f "${FileName}_4_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${FileName}_8_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${FileName}_12_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${FileName}_16_.csv" -o "../ApproximateSimulator/"