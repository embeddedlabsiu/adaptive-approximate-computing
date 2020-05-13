#!/bin/sh
#qemu-arm ./basicmath_small > output_small.txt

#if [ -z "$1" ];  then
#    /home/developer/Documents/Simulators/approximate-computing/gem5/build/ARM/gem5.opt /home/developer/Documents/Simulators/approximate-computing/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./basicmath_small	
#    exit
#fi

/home/developer/Documents/Simulators/approximate-computing/gem5/build/ARM/gem5.opt /home/developer/Documents/Simulators/approximate-computing/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./basicmath_small
