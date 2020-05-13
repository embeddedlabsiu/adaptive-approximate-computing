#!/bin/sh
#qemu-arm ./basicmath_small > output_small.txt

cp /home/developer/Documents/Simulators/approximate-computing/work/benchmarks/MiBench/basicmath-CCF/SobelFilter/src/sobel /home/developer/Documents/Simulators/approximate-computing/work/benchmarks/MiBench/basicmath-CCF/SobelFilter

if [ -z "$1" ];  then
    /home/developer/Documents/Simulators/approximate-computing/gem5/build/ARM/gem5.opt /home/developer/Documents/Simulators/approximate-computing/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./sobel 
    exit
fi

/home/developer/Documents/Simulators/approximate-computing/gem5/build/ARM/gem5.opt /home/developer/Documents/Simulators/approximate-computing/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c /src/sobel  > $1
