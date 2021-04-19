// Main program for assignment 5 - Memory Management
//
// This program will be run as follows:
//
// run_memory <json_file>

#include "memory_manager_base.h"
#include "memory_manager_first_fit.h"
#include "memory_manager_best_fit.h"
#include "nlohmann/json.hpp"

#include <getopt.h>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char ** argv)
{
    MemoryManagerBase * memory;   // Memory Manager that will be used 
    string algorithm;             // String choosing which memory manager to use
    int memory_size = 128;        // Amount of memory to allocate

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return(3);
    }
        
    // Open the input file. 
    ifstream in(argv[1]);
    if (! in.good()) {
        cerr << "Failed to open file " << argv[1] << endl;
        return(4);
    }

    nlohmann::json input_json;

    // Read the file into the json object.
    // If the input file is not in json format, this will
    // throw an exception

    try {
        in >> input_json;
    } catch (nlohmann::json::exception& e) {
        cerr << "Error: " << e.what() << endl
             << "exception id: " << e.id << endl;
        return(5);
    }


    // TODO: Process the memory_size and algorithm from the options segment
    //       of the input file. If either of these 2 options is missing, 
    //       your program should print an error message and exit.

    


    // Allocate a memory manager based on the
    // chosen algorithm.
    if (algorithm == "first_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerFirstFit(memory_size);
    } else if (algorithm == "best_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerBestFit(memory_size);
    } else {
        cerr << "Invalid algorithm specified: " << algorithm << endl;
        return(9);
    }

    // Print the initial memory setup
    memory->print();
    cout << endl;
    
    // Use this map to keep track of the relationship between the tags that are given
    // in the input file and their associated memory locations. This map should be used
    // to look up the locations for the "release" command.
    std::map<std::string, int> tagMap;

    // Iterate the entries in the input json,
    // and take the action indicated by each entry.
    for(auto action = input_json["actions"].begin(); 
        action != input_json["actions"].end();
        ++action) {
        
        // Print the action that is about to be processed
        cout << *action << endl;

        if(action->at("action") == "allocate") {
            // The allocate action takes the following keywords and values:
            //
            // action: allocate
            // process_id : Process ID that is taking the action
            // size: Size of memory to be allocated
            // tag: A tag that identifies the memory that is allocated. This tag is used
            //      in subsequent actions in the input file to take action on the particular
            //      memory that was allocated (i.e. to release it)
            
            
            // TODO: Retrieve the arguments from the input entry, and use the MemoryManager
            //       to allocate the memory. Save the relationship between the tag and the
            //       returned location in the tagMap
            
            
        } else if (action->at("action") == "release") {
            // The release action takes the following keywords and values:
            //
            // action: release
            // process_id : Process ID that is doing the release
            // tag: Tag associated with the memory to be released, which was saved
            //      when the memory for that tag was allocated.
            
            
            // TODO: Retrieve the arguments from the input entry, and use teh 
            //       MemoryMangager to release the memory. If the memory is
            //       successfully released, remove the entry from the tagMap
            
        }

        // Print the current memory layout after each action is complete
        memory->print();
        cout << endl;
    
    }


    return 0;
}