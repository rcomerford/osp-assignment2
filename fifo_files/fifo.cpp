#include "../loader.h"
#include "../simulator.h"
#include <cstdlib>

#define NUM_ARGS 2
#define SCHEDULING_ALGO "fifo"

int main(
    int argc, 
    char const *argv[]
){
    // create loader instance
    loader ld = loader();

    // validation command line arguments
    if(argc != NUM_ARGS)
    {
        cerr << "ERROR:\t" << "Program must be run in format: ./" << SCHEDULING_ALGO << " <datafile>" << endl;
    }
    else if(!ld.readFile(argv[1]))
    {
        cerr << "ERROR:\t" << "Failed to read file: " << argv[1] << endl;
    }
    else
    {
        // get pcb's loaded from file
        deque<pcb*> all_processes = ld.getPCBList();

        // initialise simulator
        time_type QUANTUM = -1;

        simulator sim = simulator(
            SCHEDULING_ALGO,
            all_processes,
            QUANTUM
        );

        // run simulation then print averages
        sim.run_simulator();
        sim.print_averages();
    }
    
    return EXIT_SUCCESS;
}
