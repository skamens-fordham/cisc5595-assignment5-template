# CISC5595 Assignment 5 - Memory Management

For this assignment we will implement a simple memory management system, including two different memory allocation algorithms.

# JSON
As we have done for our previous assignments, your program will read a json file containing the options for each run as well as a sequence of memory-related actions to simulate. 

# MemoryManagerBase

The base class for the Memory Manager defines the interface to the class. The header file (memory_manager_base.h) gives the details of the functions that should be implemented in the base class (and which will be implemented in the derived classes)

Implement the base class as instructed by following the TODO entries in `memory_manager_base.h` and `memory_manager_base.cpp`.

# MemoryManagerBestFit

The `MemoryManagerBestFit` class is derived from the `MemoryManagerBase` class. Based on the TODO entries in the header and cpp file, implement the functions as instructed.

# MemoryManagerFirstFit

The `MemoryManagerFirstFit` class is derived from the `MemoryManagerBase` class. Based on the TODO entries in the header and cpp file, implement the functions as instructed.

# execute.cpp
The file `run_memory.cpp` is the program that will execute the instructions found in the json input file. Follow the TODO entries in this file to implement this program.

# submit.txt
Once you have completed your assignment, commit it and push your repository to github. Then complete the `submit.txt` file and upload that file to Blackboard.
