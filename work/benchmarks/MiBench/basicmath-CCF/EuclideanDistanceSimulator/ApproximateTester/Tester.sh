#!/bin/bash
CURRENTDATE=`date +"%m-%d %T"`
ZeroFileName="${CURRENTDATE}"
FirstFileName="${CURRENTDATE}"
ThirdFileName="${CURRENTDATE}"

./Test.run -n 4 -t 1 -e $1 -s 1 > "${ZeroFileName}_4_.csv";
./Test.run -n 8 -t 1 -e $1 -s 1 > "${ZeroFileName}_8_.csv";
./Test.run -n 12 -t 1 -e $1 -s 1 > "${ZeroFileName}_12_.csv";
./Test.run -n 16 -t 1 -e $1 -s 1 > "${ZeroFileName}_16_.csv";

../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_4_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_8_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_12_.csv" -o "../ApproximateSimulator/"
../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_16_.csv" -o "../ApproximateSimulator/"
