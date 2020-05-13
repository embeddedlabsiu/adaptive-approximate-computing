#!/bin/bash
CURRENTDATE=`date +"%m-%d_%T"`
ZeroFileName="${CURRENTDATE}"
FirstFileName="${CURRENTDATE}"
ThirdFileName="${CURRENTDATE}"

./Test.run -n 4 > "${ZeroFileName}_4_.csv";
./Test.run -n 8 > "${ZeroFileName}_8_.csv";
./Test.run -n 12 > "${ZeroFileName}_12_.csv";
./Test.run -n 16 > "${ZeroFileName}_16_.csv";

# ../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_4_.csv" -o "../ApproximateSimulator/"
# ../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_8_.csv" -o "../ApproximateSimulator/"
# ../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_12_.csv" -o "../ApproximateSimulator/"
# ../ApproximateSimulator/LookupTableGenerator.py -f "${ZeroFileName}_16_.csv" -o "../ApproximateSimulator/"



