#!/bin/sh
#qemu-arm ./bitcnts 75000 > output_small.txt

~/ccf3/ccf/gem5/build/ARM/gem5.opt --debug-flags=CGRA,CGRA_Detailed ~/ccf3/ccf/gem5/configs/example/se_hetro.py -n 5 --cpu-type atomic -c ./bitcnts --options="750" > output_small.txt 
