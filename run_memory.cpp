// Main program for assignment 5 - Memory Management
//
// This program will be run as follows:
//
// run_memory --algorithm=<algo> --size=<memory_size> <json_files>
//    Where <algo> will be either "first_fit" or "best_fit", and
//          <size> is the number of bytes of memory to allocate
//          <json_files> is a set of one or more processes to run

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
    int memorySize = 100;         // Amount of memory to allocate

    // Use getopt_long to process the command line arguments.
    // If the algorithm argument is missing, the program
    // should fail.

    // These external variables are defined and used by the getopt()
    // functions.
    extern char *optarg;
    extern int optind, opterr, optopt;

    // The accepted arguments are as follows:
    //    - "algorithm" - either "first_fit" or "best_fit" to indicate which
    //                    memory manager to use
    //    - "size" - the amount of memory to allocate (optional - if this is)
    //               not specified, it should default to 100
    // 
    // For info on getopt_long use "man getopt_long" on a Linux host, 
    // or see https://linux.die.net/man/3/getopt_long
    



    // Allocate a memory manager based on the
    // chosen algorithm.
    if (algorithm == "first_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerFirstFit(memorySize);
    } else if (algorithm == "best_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerBestFit(memorySize);
    } else {
        cerr << "No algorithm specified!" << endl;
        return(9);
    }

    // Initial print of all the memory
    memory->print();
    cout << endl;


    // Use this map to keep track of the relationship between the tags that are given
    // in the input file and their associated memory locations. This map should be used
    // to look up the locations for other actions to be taken on the same tags.
    std::map<std::string, int> tagMap;



    // The rest of the arguments will be files in json format containing 
    // specifications for processes to be added to the table.

    // After the getopt_long processing, optind will be the index of the
    // next argument to read.

    for (; optind < argc; ++optind) {
        
        // Create a std::ifstream using the input file name.
        // For an example, see https://www.oreilly.com/library/view/c-in-a/059600298X/re556.html
        

        // Read from the ifstream into an nlohman::json object.
        // See https://github.com/nlohmann/json/blob/develop/README.md#serialization--deserialization for 
        // details. Make sure to handle any errors caused by badly formatted json files.
        // (Hint - see https://nlohmann.github.io/json/features/parsing/parse_exceptions/)
        

        // Iterate the contents of the input json, executing the actions that are indicated
        // in each entry.
        
        // See https://github.com/nlohmann/json/blob/develop/README.md#stl-like-access for details
        // on how to iterate the json object

        for (;;) // all entries in the json file 
        {

            // Each entry will contain an "action" indicating what memory action should be taken.
            // The following pseudo code gives details on how to handle each action.

            nlohmann::json entry;

            if(entry.at("action") == "allocate") {
                // The allocate action takes the following keywords and values:
                //
                // action: allocate
                // process_id : Process ID that is taking the action
                // size: Size of memory to be allocated
                // tag: A tag that identifies the memory that is allocated. This tag is used
                //      in subsequent actions in the input file to take action on the particular
                //      memory that was allocated (i.e. to read, write, or release it)

                tagMap[tag] = result_location;

            } else if (access->at("action") == "write") {
                // The write action takes the following keywords and values:
                //
                // action: write
                // process_id : Process ID that is doing the write
                // tag: Tag associated with the memory to be written to, which was saved
                //      when the memory for that tag was allocated.
                // data: Data to write to the location associated with the tag


                // Look up the given tag to get the memory location, then call the
                // write method of the memory object to perform the write.

            } else if (access->at("action") == "read") {
                // The read action takes the following keywords and values:
                //
                // action: read
                // process_id : Process ID that is doing the read
                // tag: Tag associated with the memory to be read from, which was saved
                //      when the memory for that tag was allocated.
                // length: Number of bytes to read
                // expected: The expected value that should be read. This is used for verification.
                //           the code should check that the data read matches the expected data
                

                // Look up the location using the tag given in the input file
                // Perform the read call into a local data buffer
                // Compare the data actually read with the value of the 'expected' tag

            } else if (access->at("action") == "release") {
                // The release action takes the following keywords and values:
                //
                // action: release
                // process_id : Process ID that is doing the release
                // tag: Tag associated with the memory to be released, which was saved
                //      when the memory for that tag was allocated.

                // Look up the location given the tag in the input file
                // Release the memory at that location
            }

            
            // After executing each command, print the contents of the memory block
            // data structure
            memory->print();
            cout << endl;   
        }
    }

    return 0;
}