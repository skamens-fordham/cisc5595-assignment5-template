# Implements a Memory Manager using the Best Fit Algorithm

class MemoryManagerBestFit:
    def __init__(self, size):

        # Initialize the data to an initial set of bytes
        self.data = bytearray(size)

        # This will be a list of the memory blocks
        self.blocks = []

        # We want to initialize the list of memory blocks with a single
        # block containing the information about all of the memory. 

        block = { 
            # TODO: Enter keys and values here to represent all of the information you
            #       will need to know about a single block of memory
        }

        # Append the initial block to the list of all blocks
        self.blocks.append(block)        

    # Allocate a block of memory
    def allocate(self, process_id, bytes):
        # TODO: Implement the allocate logic as follows:
        #
        #       Find the smallest unallocated block that is at least
        #       as big as the number of bytes to be implemented.
        #
        #       If the block to be assigned is exactly the same size as
        #       the amount needed, set its data values to indicate that it
        #       is assigned.
        #
        #       If the block to be assigned is bigger than the number of bytes
        #       needed, split the block, leaving one block exactly the same size
        #       as needed, and a second block with the rest of the original.
        #       Add the new remainder block to the list of blocks.
        #
        #       Return the location of the block that was allocated.
        #       If no suitable location can be found to store the new block,
        #       return -1


    # Release a block of memory
    def release(self, process_id, location):
        # TODO: Implement the "release" logic as follows:
        #
        #       Find the block that starts at the given location
        #       Entire blocks must be freed (i.e. you can't free a location
        #       that isn't at the start of a block).
        #
        #       Make sure the block to be released is owned by the process_id
        #       that is indicated.
        #
        #       Change the attributes of the block that is being released
        #       to indicate that it is no longer allocated.
        #
        #       Return true if the block was released, or false otherwise

    
    # Method that is called when someone calls print() on a ProcessTable.
    # This invokes the __str__ method for each active process (i.e. each
    # process with a pid that isn't -1), to print that process on its own line
    def print(self):
        for b in self.blocks :
            print (b)
        


