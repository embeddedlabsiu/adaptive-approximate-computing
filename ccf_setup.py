#!/usr/bin/python
import os
import string

def fileReplace(filename, search, replace):
	success = 1
	data = None
	with open(filename, "r") as f:
		data = f.readlines()
		
	i = 0
	for line in data:
		if(search in line):
			data[i] = replace + '\n'
			success = 0
			break
		i += 1;
	with open(filename, "w") as f:
		f.writelines(data)
	return success

def main():
	dir_path = os.path.dirname(os.path.realpath(__file__))
	if(os.path.exists(dir_path + "/gem5") == False):
		print("It appears this script is not in the ccf directory. Please move it to the ccf directory")
		return
		
	xdim = int(input("Input CGRA X dimension: "))
	if(xdim < 1 or xdim > 64):
		print("Invalid X dimension input. Please enter an integer between 1 and 64. You entered " + str(xdim))
		return
		
	ydim = int(input("Input CGRA Y dimension: "))
	if(ydim < 1 or ydim > 64):
		print("Invalid Y dimension input. Please enter an integer between 1 and 64. You entered " + str(xdim))
		return
		
	if(fileReplace("scripts/map.sh", 'toolchain="', 'toolchain="' + dir_path + '"')):
		print('No replacement found in "scripts/map.sh"')
		
	if(fileReplace("scripts/opt.sh", 'toolchain="', 'toolchain="' + dir_path + '"')):
		print('No replacement found in "scripts/opt.sh"')
	
	if(fileReplace("scripts/CGRALib/cgra.c", "  int II = kernelsize/(", "  int II = kernelsize/(" + str(xdim*ydim) + "); // Edited by python script")):
		print('No replacement found in "scripts/CGRALib/cgra.c"')
	if(fileReplace("scripts/CGRALib/cgra.c", "  int epiLength = episize/", "  int epiLength = episize/" + str(xdim*ydim) + "; // Edited by python script")):
		print('No replacement found in "scripts/CGRALib/cgra.c"')
	if(fileReplace("scripts/CGRALib/cgra.c", "  int prolength = prosize/", "  int prolength = prosize/" + str(xdim*ydim) + "; // Edited by python script")):
		print('No replacement found in "scripts/CGRALib/cgra.c"')
	if(fileReplace("scripts/CGRALib/cgra.c", "  *(initCGRA + 7*(loopID-1) + 6) = livevar_st_size/", "  *(initCGRA + 7*(loopID-1) + 6) = livevar_st_size/" + str(xdim*ydim) + "; // Edited by python script")):
		print('No replacement found in "scripts/CGRALib/cgra.c"')
	
	if(fileReplace("scripts/CGRALib/cgracc", 'toolchain="', 'toolchain="' + dir_path + '"')):
		print('No replacement found in "scripts/CGRALib/cgracc"')
	
	if(fileReplace("scripts/CGRALib/run.sh", "X=", "X=" + str(xdim))):
		print('No replacement found in "scripts/CGRALib/run.sh"')
	if(fileReplace("scripts/CGRALib/run.sh", "Y=", "Y=" + str(ydim))):
		print('No replacement found in "scripts/CGRALib/run.sh"')
	if(fileReplace("scripts/CGRALib/run.sh", 'toolchain="', 'toolchain="' + dir_path + '"')):
		print('No replacement found in "scripts/CGRALib/run.sh"')
	
	if(fileReplace("InstructionGenerator/CGRAdefinitions.h", "#define CGRA_XDim ", "#define CGRA_XDim " + str(xdim))):
		print('No replacement found in "InstructionGenerator/CGRAdefinitions.h"')
	if(fileReplace("InstructionGenerator/CGRAdefinitions.h", "#define CGRA_YDim ", "#define CGRA_YDim " + str(ydim))):
		print('No replacement found in "InstructionGenerator/CGRAdefinitions.h"')
	
	if(fileReplace("gem5/src/cpu/atomiccgra/CGRAdefinitions.h", "#define CGRA_XDim ", "#define CGRA_XDim " + str(xdim))):
		print('No replacement found in "gem5/src/cpu/atomiccgra/CGRAdefinitions.h"')
	if(fileReplace("gem5/src/cpu/atomiccgra/CGRAdefinitions.h", "#define CGRA_YDim ", "#define CGRA_YDim " + str(ydim))):
		print('No replacement found in "gem5/src/cpu/atomiccgra/CGRAdefinitions.h"')
	
	if(fileReplace("gem5/src/cpu/timingcgra/CGRAdefinitions.h", "#define CGRA_XDim ", "#define CGRA_XDim " + str(xdim))):
		print('No replacement found in "gem5/src/cpu/timingcgra/CGRAdefinitions.h"')
	if(fileReplace("gem5/src/cpu/timingcgra/CGRAdefinitions.h", "#define CGRA_YDim ", "#define CGRA_YDim " + str(ydim))):
		print('No replacement found in "gem5/src/cpu/timingcgra/CGRAdefinitions.h"')
	
	if(fileReplace("install", "$newpath/scripts/install_dependecies", "# $newpath/scripts/install_dependecies")):
		print('No replacement found in "install"')
	if(fileReplace("install", "sudo cp $newpath/scripts/CGRALib/cgracc /usr/bin", "# sudo cp $newpath/scripts/CGRALib/cgracc /usr/bin")):
		print('No replacement found in "install"')
	if(fileReplace("install", "sudo chmod +x /usr/bin/cgracc", "# sudo chmod +x /usr/bin/cgracc")):
		print('No replacement found in "install"')
	
	if(fileReplace("work/benchmarks/MiBench/basicmath-CCF/basicmath13/Makefile", "CC = ", "CC = ../../../../../scripts/CGRALib/cgracc")):
		print('No replacement found in "work/benchmarks/MiBench/basicmath-CCF/basicmath13/Makefile"')
	
	if(fileReplace("work/benchmarks/MiBench/basicmath-CCF/basicmath13/runme_small.sh", "~/gem5/build/ARM/gem5.opt ~/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./basicmath_small > output_small.txt", str(dir_path) + "/gem5/build/ARM/gem5.opt " + str(dir_path) + "/gem5/configs/example/se_hetro.py -n 2 --cpu-type atomic -c ./basicmath_small > output_small.txt")):
		print('No replacement found in "work/benchmarks/MiBench/basicmath-CCF/basicmath13/runme_small.sh"')
	
	print("Done")

if __name__ == "__main__":
	main()
