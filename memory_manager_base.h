#ifndef CISC5595_MEMORY_MANAGER_BASE_H
#define CISC5595_MEMORY_MANAGER_BASE_H

#include <list>

// memory_manager_base.h
//
// Base class of a Memory manager.

class MemoryManagerBase {

    public:

        // Allocate memory
        // This is a pure virtual function; it will be implemented in the 
        // derived classes.
        //
        // Arguments:
        //      process_id: The id of the process that is allocating the memory
        //      bytes: Number of bytes to allocate
        // Returns the location of the allocated memory in the block that is managed by 
        // this class.

        virtual int allocate(int process_id, int bytes) = 0;

        // Release memory
        // This is a pure virtual function; it will be implemented in the 
        // derived classes.
        //
        // Arguments:
        //      process_id: The id of the process that is releasing the memory.
        //                  Only the process that allocated the memory is allowed to release it
        //      location: The location of the allocated memory to release. Only the first
        //                location within an allocated block can be released
        // Returns true if the memory is successfully released, false otherwise
        virtual bool release(int process_id, // Process ID that is releasing the memory
                             int location    // Memory location to release
        ) = 0;


        // Print the contents of memory
        // This should print one line for each block of memory, including all the information
        // associated with the block
        virtual void print();

    
    // The below items are protected (rather than private) so they can be 
    // accessed by the derived classes.

    protected:
        // The block of memory itself. This should be allocated by the 
        // constructor
        char * m_data;

        // Data structure to keep track of allocated memory
        struct memory_block {
            // Define the data members in this structure that will keep track
            // of the available blocks of memory.
            // Make sure to keep track of which process owns each block
        };

        // List of blocks of memory
        std::list<struct memory_block> m_blocks;
};

#endif