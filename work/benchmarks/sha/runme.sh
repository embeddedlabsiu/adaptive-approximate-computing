#!/bin/sh
~/ccf3/ccf/gem5/build/ARM/gem5.opt ~/ccf3/ccf/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./main > output.txt
