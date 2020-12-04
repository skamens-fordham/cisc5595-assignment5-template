#ifndef CISC5595_MEMORY_MANAGER_BEST_FIT_H
#define CISC5595_MEMORY_MANAGER_BEST_FIT_H

#include "memory_manager_base.h"
#include <list>

// memory_manager_best_fit.h
//
// Class implementing a best fit memory manager

class MemoryManagerBestFit : public MemoryManagerBase {

    public:

        // Constructor.
        // This class will alocate a buffer of the indicated size to hold
        // the data in "memory". It also initializes the data structure
        // that tracks the memory blocks
        MemoryManagerBestFit(int size);
        
        // Allocate the indicated amount of memory.
        // See the comments in memory_manager_base.h for details
        virtual int allocate(int process_id, int bytes);

        // Release the memory at the given location.
        // See the comments in memory_manager_base.h for details
        virtual bool release(int process_id, int location);

    private:      

};

#endif