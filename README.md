# **Approximate Computing**

## **Disclaimer**
The code in this repository has been based on the CCF (CGRA Compilation Framework) project, found [here](https://github.com/MPSLab-ASU/ccf). Please follow that link for a complete installation guide.

### **CCF**
For all documentation of CCF, see CCF_README.md and CCF Manual.pdf.

## **Approximate Computing**
1. **Basic Overview:** All of the files for Approximate Computing are located in the folder ApproximateComputing, located at the root directory of the folder. Under this folder, there are subfolders that represent the location in CCF where the contained files implement functionality. The files in each subfolder are then soft linked to the corresponding location in the CCF project. Additionally, under each subfolder, there is a README.txt file that describe where each file is located in the CCF project. 
2. **Approximate Computing Folder Guide:**
	* **DynamicRuntimeCGRAControl Folder:** This folder contains the files necessary to dynamically control the CGRA during runtime. 
		* **ArithmeticLogicUnitList.h and .c:** These files wrap the generic list with API that is specific to dynamic runtime control of the cgra. It contains the ArithmeticLogicUnitNode structure, which contains the associated PE number and its respective LogicUnitDescription. The LogicUnitDescription structure describes the approximate settings for each log unit. Additionally, these files contain the functions that create a linked list of specific arithmetic operations. For instance, calling the getAdderList function will return a linked list of all the adders in the CGRA with a pointer to the respective approximate settings. The files also contain a function to find a specific PE by number.
		* **CGRAHelperFunctions.h and .c:** These files define the structures for and the typedef of the CGRA. The LogicUnitDescription structure describes the approximate settings for each log unit. These files also define the ArithmeticPEDescription structure, which contains the LogicUnitDescription structure for each arithmetic operation. These files also typedef the CGRA data type, which is simply an array of ArithmeticPEDescriptions. Associated functions for each structure are also located in these files.
		* **DynamicCGRAControl.h and .c:** Defines the DynamicCGRAControl structure, which contains the CGRA, size of the cgra, and a linked list of each approximate arithmetic operation. Additionally, it contains API for utilizing the DynamicCGRAControl, and a function, called dynamicControl, that is called cyclically to control the CGRA at runtime. 
		* **LinkedList.h and .c:** This is a generic linked list in the C programming language. Each node contains a void pointer to the data being stored in the node, which makes each node able to contain any type of data. This linked list implementation contain the **BASIC** API for a linked list. However, advanced API is omitted because of time and necessity.
		* main.c: A simple main to test the files in the folder.
	* **Gem5 Folder:** This folder contains files that implement approximate computing's functionality in the gem5 simulator. 
		* **ApproximateHardware Sub-Folder:** 
			* **Adders Sub-Folder:** Contains all of the hardware team's implementation of each adder. All of the sub folders contain the files given by the hardware team's implementation of the respective adder.
				* **Adders.h:** This file contains the static class that wraps all of the adders in the project by creating methods for each adder's hardware implementation.  
			* **Multipliers Sub-Folder:** Contains all of the hardware team's implementation of each multiplier. All of the sub folders contain the files given by the hardware team's implementation of the respective multiplier.
				* **Multipliers.h:** This file contains the static class that wraps all of the mutlipliers in the project by creating methods for each mutliplier's hardware implementation.  
			* **Subtractors Sub-Folder:** Contains all of the hardware team's implementation of each subtractors. All of the sub folders contain the files given by the hardware team's implementation of the respective subtractors.
				* **Subtractors.h:** This file contains the static class that wraps all of the mutlipliers in the project by creating methods for each subtractor's hardware implementation.  
		* **ApproximateComputing.h and .c:** This class wraps the hardware implementations, located in the **ApproximateHardware Sub-Folder**, given by the hardware team. It provides enums for each hardware implementation to allow calls to specific hardware types in a single method, which acts as an abstraction layer between the gem5 framework and the approximate computing implementation. This is because all the approximate calls are called from the addition, multiplication, and subtraction methods located in these files. Therefore, CGRAPE.cpp's *Execute* method calls the appropriate arithmetic operation with the approximation given settings.
		* **FileParser.h and .c:** This class parses the CGRA settings file, named **CGRA_PE_Description.txt**, and returns a data structure that represents the CGRA settings. The data structure, named **Results**, is made up of the **CgraPeDescription** structure and an integer that represents the number of results, which is the number of PEs that are available. The **CgraPeDescription** structure contains all of the hardware descriptions of each arithmetic operation that approximate computing utilizes. Also, in these files, are convenience methods to print and delete the whole result and to print a specific **CgraPeDescription**. 
		* **LoggerFactory.h and .c:** This class is based on the factory design pattern, which creates various items. Essentially, all this class does is "build" loggers with the given arguments. 
		* **LoggerHandler.h and .c:** This class handles logging various items to a file. This is helpful in the gem5 framework because there is no terminal to utilize printf. So, the logger acts as a printf debugging mechanism that prints to a file instead of the terminal. To utilize the logger, give the file path of the log file and use the appropriate overloaded log method to log to the file.
	* **InstructionGenerator Folder:** This folder contains the files to work with the instruction generator, located in the folder of the same name in the root directory of the repo. 
		* **ApproximateComputing.h:** This class logs the PEs that are involved in the CGRA's kernel code. It generates a file that describes the PEs and respective arithmetic operations are utilized in the CGRA's kernel code. 
		* **Notes:** This approach seems to work with Basicmath13, but that is the only way it has been tested. Therefore, if PEs involved in a loop do not seem to match the results in the output file, this is a good place to start checking for errors.  
3. **Modifications Of Gem5's Original Files:** The following Gem5 files were modified to implement Approximate Computing.
	* **atomiccgra.hh and .cpp:** In these files, a Logger was added, a method to log CGRA statistics to a file, and a method to change the CGRA setup during runtime. The logger serves as debugging tool for checking the results of the runtime. The logStatistics() method logs each PE's arithmetic operations performed to a file. The checkAndHandleNewCGRASettings() method checks whether the CGRA_PE_Description.txt has changed, and if so,loads the new setting and modifies the CGRA accordingly.   
	* **CGRAPE.hh and .cpp:** In these files, an enum called **HardwareType**, a structure called **Statistics**, and methods to set and get approximate computing settings. The **HardwareType** enum describes the hardware that has approximate computing implementations. The **Statistics** structure holds the pertinent statistics for the CGRA. 
4. **Modifications Of Instruction Generator Original Files:** The only file that changes in this directory is the insgen.cpp. 
	* **insgen.cpp:** This file adds a file, called **ApproximateDebugFile.txt**, that logs the details of the prologue, kernel, and epilog CGRA operations. It also creates a file, which is the main purpose of the changes, that describes the PEs involved and arithmetic operations that are performed in the kernel of the CGRA's runtime. 
5. **Approximate Computing Files:** This section provides information about the files that are used to control and debug approximate computing.
	* **AtomicCGRA.txt:** This file is used for debugging the AtomicCGRA class by logging the CGRAP PE settings parsed by the parser. Therefore, anytime the CGRA settings change, this file should reflect those changes. The file is located wherever the executable gem5 ran is located. In the current setup, it is located at approximate-computing/work/benchmarks/MiBench/basicmath-CCF/basicmath13.  
	* **CGRA_PE_Description.txt:** This file is what gem5 uses to change the CGRA settings during runtime. Therefore, any time the CGRA settings need to change **this files must change** to load the new setting on the CGRA. Using a file as a mechanism for runtime communication is admittedly less than ideal, but due to the complexity of gem5, it is a decent compromise. Ideally, a IPC method, like a pipe, would be best, but this setup works without the complexity of adding communication handling in gem5. Like the AtomicCGRA.txt file, this file is located wherever the executable gem5 ran is located. 
	* **PE.txt:** This file just logs the different arithmetic operations each PE executes. This file acts as a way to check the CGRA settings have been parsed correctly. Like the AtomicCGRA.txt file, this file is located wherever the executable gem5 ran is located. 
	* **ApproximateDebugFile.txt:** This file logs the prologue, kernel, and epilogue information the instruction generator code produces. It is not the most useful file, but it acts as a check for the ArithmeticPEsList.txt file. This file is located in the executable's directory under the CGRAExec/L1 and CGRAExec/L2. 
	* **ArithmeticPEsList.txt:** This file is produced by the Approximate Computing code located in the Instruction Generator. This file contains the PEs and arithmetic operations of the PE for the kernel code. This can be used to dynamically control the CGRA at runtime. This file is located in the executable's directory under the CGRAExec/L1 and CGRAExec/L2.
6. **Adding Additional Approximate Hardware:** This section provides step-by-step instructions on how to add additional Approximate Hardware to the Gem5 simulator. 
	1. Add a folder to the corresponding arithmetic operation and move the given files to the location. The arithmetic operation folder is located at approximate-computing/ApproximateComputing/gem5/ApproximateHardware/
	2. Rename the given library.h and .c files to be more specific to the given hardware implementation. For instance, consider the Exact Adder implementation. The associated library.h and .c would be renamed Adder32ExactLibrary.h and .c. Then, add the header guard to the newly renamed file.
	3. Using the Exact Adder example, in the approximate-computing/ApproximateComputing/gem5/ApproximateHardware/Adders/Adders.h files, add a method that aptly describes the new hardware. In this case add32Exact is the method name. 
	4. Rename the .c file that describes the hardware and rename it to reflect the specific hardware device. 
	5. In the newly renamed .c file, add the static keyword to all of the helper functions in the file. **DO NOT** add static to the main function of the file. 
	6. Still in the newly renamed .c file, add ApproximateComputing::Adders:: to the beginning of the main function. 
	7. In the approximate-computing/ApproximateComputing/gem5/ApproximateComputing.h file, add a new enum under the appropriate enum. Still using the Exact Adder, add an enum called Exact under the AdderTypes structure. 
	8. In the approximate-computing/ApproximateComputing/gem5/ApproximateComputing.cpp file, add a case to the switch statement in the appropriate arithmetic method. Still using the Exact Adder, in the addition method, add the case using the enum created in the previous step. In the case, call the associated method that was created in step 3. 
	9. In the root directory of the repo, call the recompileGem5 script to rebuild the gem5 simulator. The above changes should take effect after rebuilding the gem5 simulator.
	10. As a note, just doing the above steps will allow gem5 to use new hardware, but that does not mean any code like RAMP or Dynamic Control can automatically utilize the new hardware too. 
7. **Compilation Work Flow:** This section describes the **basic** steps of making the basic math 13 executable (located approximate-computing/work/benchmarks/MiBench/basicmath-CCF/basicmath13). 
	1. Clang is called on cgra.c, which emits the llvm file combinedIR.ll.
	2. The opt.sh script is called, which in turn calls llvmbuild/bin/opt on several files. 
	3. The opt.sh checks if the CGRAExec directory exists. If so, llvmbuild/bin/opt is called on even more files.
	4. After opt.sh has run, clang-5.0 is run to apply remaining optimizations.
	5. The cgracc script also checks for the existence of the CGRAExec directory. If the directory exists, the scripts/CGRALib/run.sh is called. The run.sh in turn calls the map.sh script. The map.sh script calls the RAMP program, then it calls the nodefile executable. 
	6. Finally, run.sh calls the op code generator, and the build is complete.
8. **Runtime Work Flow:** Once the above step has been completed, the executable is ready to run. In this section, the runtime work flow of Approximate Computing is described. For this entire section, approximate-computing/work/benchmarks/MiBench/basicmath-CCF/basicmath13/runme_small.sh is used. 
	1. In order to run the basicmath_small executable, the runme_small.sh must be executed. To accomplish this, open a terminal and navigate to the basicmath13 folder. Then, type ./runme_small.sh, which executes the program.
	2. The runme_small.sh calls the approximate-computing/gem5/configs/example/se_hetro.py python script sets up the gem5.opt executable (the simulator), which in turn runs the basicmath_small executable. 
	3. Next, a **basic** overview of the actual runtime of gem5 with respect to the contributions of Approximate Computing. Approximate Computing has no contributions until the CGRA starts running. 
		1. When the CGRA starts running, the CGRA's prologue operations load the CGRA with necessary data to execute the kernel. At this time, Approximate Computing has no contributions to the prologue. 
		2. Afer the prologue has completed, the kernel code is executed. The kernel and other executions are driven by the tick method, which, as expected, gets called every tick of the CGRA. The tick method does many things, but the pertinent item is calling the CGRA_Execution method. One of the first things the CGRA_Execution method does is call the checkAndHandleNewCGRASettings method. This method checks the CGRA setup file, called CGRA_PE_Description.txt, and, if the file has changed since the last tick, will load the new CGRA settings. 
		3. After the kernel code has completed, the epilogue code collects the relevant CGRA data and the simulation reverts back to the ARM CPU. 

## **Acknowledgements**

If you use the code of this repository in your work, please use the following reference

*J. Dickerson, I. Galanis, ZG. Tasoulas, L. Kinley and I. Anagnostopoulos, __"Adaptive Approximate Computing on Hardware Accelerators targeting IoT applications,"__*

```bibtex
@INPROCEEDINGS{
    author={J. {Dickerson} and I. {Galanis} and ZG. {Tasoulas} and L. {Kinley} and I. {Anagnostopoulos}},
    title={Adaptive Approximate Computing on Hardware Accelerators targeting IoT applications},
    year={2020},
    volume={},
    number={},
}
```

We would like to thank the following contributors for their help:

- [Jonathan Dickerson](mailto:jonathan.dickerson@siu.edu)
- [Ioannis Galanis](mailto:ioannis.galanis@siu.edu)
- [Zois Gerasimos Tasoulas](mailto:zoisgerasimos.tasoulas@siu.edu)
- [Lincoln Kinley](mailto:lincoln.kinley@siu.edu)

