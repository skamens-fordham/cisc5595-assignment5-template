#include "memory_manager_base.h"
#include <string.h>
#include <iostream>

bool MemoryManagerBase::write(int process_id, int location, const char * data, int length)
{
   // Implement the code here to write the data into the MemoryManager's memory buffer.
   //
   // Be sure to verify that the location being written to is owned by the given
   // process_id, and that the data fits inside the block as allocated.
   //
   // return true for a successful write, and false for a failed write
}


bool MemoryManagerBase::read(int process_id, int location, char * data, int length)
{
   // Implement the code here to read the data from  the MemoryManager's memory buffer.
   //
   // Be sure to verify that the location being read from is owned by the given
   // process_id, and that the data being read is all in the single block being accessed
   //
   // return true for a successful write, and false for a failed write
}


void MemoryManagerBase::print()
{
    // Cycle through all of the blocks and and print the information about each one
    // on a single line.    
}

