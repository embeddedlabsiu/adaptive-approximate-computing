CCF Approximate CGRA Simulation Manual
Lincoln Kinley

Step 1 - Installation
	Download from git and install
	
		git clone https://github.com/cmlasu/ccf.git
	
	open install
	lines 48 though 59 and 75 and 76 include some sudo commands
	If this is the first time installing ccf on the computer, leave these in place
	If you have already installed ccf on the computer you can comment out lines 48 though 59 and 75 and 76
	save and close install
	
		cd ccf
		./install
	
	This will take about 30 to 45 minutes to install
	
	Once ccf is installed you are ready to start simulating CGRAs
	You can get right into it, but for how to make modifications continue reading
	
	
Step 2 - General Modifications
	There are a few modifications that can be made to CCF to make it easier to use
	
	The author of CCF hardcoded execution paths of their own system. 
	Modify the file paths in the following files of the scripts directory and sub directories.
		- scripts/map.sh
		- scripts/opt.sh
		- scripts/CGRALib/cgracc
		- scripts/CGRALib/run.sh
	The file path is refered to in the variable "toolchain"
	
	When installing cgracc, a default cgracc will be installed system wide
	cgracc defines the size of the CGRA, so if you are simulating different CGRA sizes it's a good idea to call cgracc from the specific ccf file
	systemwide modification of the cgracc script should be prevented by commenting out the sudo lines in (1 - Installation)
	An example of how to call cgracc properly from basicmath13
		open work/benchmarks/MiBench/basicmath-CCF/basicmath13/Makefile 
		change "CC = cgracc"
		to "CC = ../../../../../scripts/CGRALib/cgracc"
		
	Also, all of the runme scripts in the work directory do not have the proper filepath, another instance of filepath being hardcoded
	all of the runme scripts in the work directory (go to basicmathXX/bitcountXX) 
	must have the location of gem5.opt and se_hetro.py changed to their actual location
	
	There is a python script that will make all of these changes for you, ccf_setup.py
	It will also change the CGRA size covered in (Step 3 - Modifying the CGRA Size)


Step 3 - Modifying the CGRA Size
	CCF has a deafult CGRA size of 4 by 4
	This can be changed but gem5 and cgracc must be recompiled every single time
	Files that need to be changed to modify the CGRA size are
	All instances of xdim and ydim below must be integers supplied by you
	for example "int II = kernelsize/(32);" would be a 6 by 6 CGRA
		- scripts/CGRALib/cgra.c
			int II = kernelsize/(xdim*ydim);
			int epiLength = episize/(xdim*ydim);
			int prolength = prosize/(xdim*ydim);
			*(initCGRA + 7*(loopID-1) + 6) = livevar_st_size/(xdim*ydim);
		- scripts/CGRALib/run.sh
			X=xdim
			Y=ydim
		- InstructionGenerator/CGRAdefinitions.h
			#define CGRA_XDim xdim
			#define CGRA_YDim ydim
		- gem5/src/cpu/atomiccgra/CGRAdefinitions.h
			#define CGRA_XDim xdim
			#define CGRA_YDim ydim
		- gem5/src/cpu/timingcgra/CGRAdefinitions.h
			#define CGRA_XDim xdim
			#define CGRA_YDim ydim
			
	After you make these changes you will need to recompile gem5 and cgracc
	
	There is a python script that will make all of these changes for you, ccf_setup.py
	It will also make changes outlined in (Step 2 - General Modifications)
	
	
Step 4 - Modifying CGRA Hardware
	The Hardware of the CGRA is outlined in gem5
	gem5 does not do a system level simulation of the hardware
	instead it does an implementation of the hardware
	because of this we cannot determine power savings and processing speedup from approximation
	We can run tests and get the correct output though.
	The logic for the CGRA is determined in /gem5/src/cpu/atomiccgra/CGRAPE.cpp
	in the function void CGRA_PE::Execute()
	The Logic of all opcodes can be modified
	The OPCodes for Add, Subtract, Mult, Div, and Rem can be approximated
	My implementation of approximate modules uses 32 bit bitsets to save memory

	
Step 5 - Using Approximation Modules in CCF
	I have already developed approximation modules for the CGRA
	These approximation modules use three different adders and two different multipliers, not counting exact.
	The functions for use are approxAdd, approxSub, and approxMult
	
	approxAdd takes four inputs
		the first number to be added (int)
		the second number to be added (int)
		the number of bits to be approximated (int)
		the approximation method (int)
	and returns the result of the first two inputs added together using the last two inputs as parameters
	
	approxSub takes four inputs
		the first number to be subtracted (int)
		the second number to be subtracted from the first number (int)
		the number of bits to be approximated (int)
		the approximation method (int)
	and returns the result of the first number minus the second number using the last two inputs as parameters
	
	note that both numbers should be positive
	approxSub currently causes issues when programs are ran on ccf. I have not been able to verify if the issue is with gem5
	or if the issue is that the application cannot be approximated. The logic of subtract has been tested and verified.
	
	approxMult takes five inputs
		the first number to be multiplied (int)
		the second number to be multiplied (int)
		the number of bits to be approximated (int)
		the approximation method of multiplication (int)
		the approximation method of addition (int)
	and returns the result of the first number times the second number using the last three inputs as parameters
	
	I'm not sure why, but this appears to work with negative numbers as inputs
	Maybe test negative numbers further
	
	These three functions take integers as input and convert them to 32 bit long bitsets, which allows for bitwise simulation of hardware
	The size of the bitset is 32 to match the size of an integer, however it could be increased by changing #define BITSET_SIZE 32
	Since the multiplication is recursive, bitset size could be potentially infinite
	
	These functions support exact arithmetic, which can be achived by setting the number of bits to be approximated to zero
	or setting the approximation method to an invalid method (add, not 0, 1, or 3; mult, not 0 or 1)
	I generally set the method to -1 to signify exact operations.
	
	These approximation modules are very slow. This is a result of using a bitset, which saves memory at the cost of performance
	

Step 6 - Developing for CCF
	When developing for CCF, find a performance critical loop and put #pragma CGRA before the loop
	Compile the program with cgracc
	cgracc will try to compile your cgra, and it will notify you if it failed to compile
	Developing for CCF comes with limitations
		The CGRA can only have up to 30 instructions (may be possible to modify but haven't made progress)
		Loops cannot have system calls (getting input from user, printing, reading file, etc)
		The CGRA cannot have function calls in the loop
		Loops cannot have nested loops
		CGRA can only do integer arithmetic
		
