# CISC5595 Assignment 5 - Memory Management

For this assignment we will implement a simple memory management system, including two different memory allocation algorithms.

# JSON
This assignment uses an input file in JSON format which will be used to test your memory management classes. This class will be incorporated into your test program using 
```
#include <nlohmann/json.hpp>
```
For details on how to use this json library, see https://github.com/nlohmann/json/blob/develop/README.md. 

# MemoryManagerBase

The base class for the Memory Manager defines the interface to the class. The header file (memory_manager_base.h) gives the details of the functions that should be implemented in the base class (and which will be implemented in the derived classes)

Implement the base class as instructed in `memory_manager_base.h` and `memory_manager_base.cpp`.

# MemoryManagerBestFit

The `MemoryManagerBestFit` class is derived from the `MemoryManagerBase` class. Based on the comments in the header and cpp file, implement the functions as instructed.

# MemoryManagerFirstFit

The `MemoryManagerFirstFit` class is derived from the `MemoryManagerBase` class. Based on the comments in the header and cpp file, implement the functions as instructed.

# memory_access.json
The file `memory_access.json` is an input file with a set of memory instructions that will be executed by your test program. 

The comments in `run_memory.cpp` (see below) give the details of the json keywords that should be used for each of the supported commands.

# run_memory.cpp
The file `run_memory.cpp` is the test program that will execute the instructions found in the json input file. Follow the instructions in this file to implement this program.
