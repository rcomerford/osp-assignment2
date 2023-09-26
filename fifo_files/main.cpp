#include "../loader.h"
#include "../simulator.h"
#include "fifo.h"
#include <cstdlib>

#define NUM_ARGS 2

int main(
    int argc, 
    char const *argv[]
){
    // create loader instance
    loader ld = loader();

    // validation command line arguments
    if(argc != NUM_ARGS)
    {
        cerr << "ERROR:\t" << "Program must be run in format: ./fifo <datafile>" << endl;
    }
    else if(!ld.readFile(argv[1]))
    {
        cerr << "ERROR:\t" << "Failed to read file: " << argv[1] << endl;
    }
    else
    {
        // get pcb's loaded from file
        deque<pcb*> all_processes = ld.getPCBList();

        // create fifo scheduling simulation
        fifo fifo_sim = fifo(all_processes);

        // run simulation then print averages
        fifo_sim.run_simulator();
        fifo_sim.print_averages();
    }
    
    return EXIT_SUCCESS;
}
