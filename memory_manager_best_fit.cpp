#include "memory_manager_best_fit.h"
#include <cstring>


MemoryManagerBestFit::MemoryManagerBestFit(int size)
{
    // Allocate the block of memory that we will manage
    m_data = new char[size];

    // Set the contents of the block of memory to all zero's (0)
    // (for help, see https://man7.org/linux/man-pages/man3/memset.3.html)


    // Set up the list of memory blocks with the info for this initial
    // unallocated block.
    memory_block b;
    // Fill in the appropriate values here based on the data elements
    // you added in the header file.


    // Add the block to the list of blocks
    m_blocks.push_back(b);
}


// Allocate a block of memory of the given size
// Find the unallocated block that has the best fit
// for the number of bytes being allocated.
int MemoryManagerBestFit::allocate(int process_id, int size) 
{
    // Find the smallest unallocated block that is at least
    // as big as the number of bytes to be implemented.

    // If the block to be assigned is exactly the same size as
    // the amount needed, set its data values to indicate that it
    // is assigned.

    // If the block to be assigned is bigger than the number of bytes
    // needed, split the block, leaving one block exactly the same size
    // as needed, and a second block with the rest of the original.
    // Add the new remainder block to the list of blocks.

    // Return the location of the block that was allocated.
}


// Release memory
bool MemoryManagerBestFit::release(int process_id, int location) 
{
    // Find the block that starts at the given location
    // Entire blocks must be freed (i.e. you can't free a location
    // that isn't at the start of a block).

    // Make sure the block to be released is owned by the process_id
    // that is indicated.
    
    // Change the attributes of the block that is being released
    // to indicate that it is no longer allocated.
}



