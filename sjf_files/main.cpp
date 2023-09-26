#include "../loader.h"
#include "sjf.h"
#include <cstdlib>
#include <algorithm>

using std::sort;

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
        cerr << "ERROR:\t" << "Program must be run in format: ./sjf <datafile>" << endl;
    }
    else if(!ld.readFile(argv[1]))
    {
        cerr << "ERROR:\t" << "Failed to read file: " << argv[1] << endl;
    }
    else
    {
        // get pcb's loaded from file
        deque<pcb*> all_processes = ld.getPCBList();

        // sort all_processes deque
        sort(
            all_processes.begin(), 
            all_processes.end(),
            [](const pcb* lhs, const pcb* rhs) {
                return (lhs->get_burst_time() < rhs->get_burst_time());
            }
        );

        // create sjf scheduling simulation
        sjf sjf_sim = sjf(all_processes);

        // run simulation then print averages
        sjf_sim.run_simulator();
        sjf_sim.print_averages();
    }
    
    return EXIT_SUCCESS;
}