#!/usr/bin/python3

from memory_manager_first_fit import MemoryManagerFirstFit
from memory_manager_best_fit import MemoryManagerBestFit

import json
import sys

def main():

    # Initialize some variables that will be used later on
    memory_size = 128
    algorithm = ""
    memory = None

    # First read the input file

    if (len(sys.argv) != 2) :
        sys.exit("Usage: " + sys.argv[0] + " <input file>")

    input = {}

    with open(sys.argv[1]) as f:
        input = json.load(f)

    # TODO: Retrieve the memory_size and algorithm from the options segment.
    #       If either of these 2 options is missing, your program should print
    #       an error message and exit 



    # Allocate a memory manager based on the chosen algorithm
    if(algorithm == 'first_fit'):
        memory = MemoryManagerFirstFit(memory_size)
    elif(algorithm == 'best_fit'):
        memory = MemoryManagerBestFit(memory_size)
    else :
        sys.exit("Error: Invalid value for options/algorithm")

    # Print the initial memory setup
    memory.print()
    print("\n")


    # Use this map to keep track of the relationship between the tags that are given
    # in the input file and their associated memory locations. This map should be used
    # to look up the locations for the "release" command.
    tagMap = {}

    # Process the actions
    for action in input['actions']:

        # Print the action that is about to be processed
        print(action)

        if (action["action"] == "allocate") :
            # The allocate action takes the following keywords and values:
            #
            # action: allocate
            # process_id : Process ID that is taking the action
            # size: Size of memory to be allocated
            # tag: A tag that identifies the memory that is allocated. This tag is used
            #      in subsequent actions in the input file to take action on the particular
            #      memory that was allocated (i.e. to release it)
            
            
            # TODO: Retrieve the arguments from the input entry, and use the MemoryManager
            #       to allocate the memory. Save the relationship between the tag and the
            #       returned location in the tagMap

        elif (action["action"] == "release"):
            # The release action takes the following keywords and values:
            #
            # action: release
            # process_id : Process ID that is doing the release
            # tag: Tag associated with the memory to be released, which was saved
            #      when the memory for that tag was allocated.
            
            
            # TODO: Retrieve the arguments from the input entry, and use teh 
            #       MemoryMangager to release the memory. If the memory is
            #       successfully released, remove the entry from the tagMap            

        # We print the current memory layout after each action is complete        
        memory.print()
        print("\n")

    return 0

if __name__ == "__main__":
    main()
