#include "../loader.h"
#include "../simulator.h"
#include <cstdlib>

#define NUM_ARGS 3
#define SCHEDULING_ALGO "rr"

using std::stoi;

/**
 * Validates INTEGER command-line input.
*/
bool isNumber(const string& s)
{
    bool result = true;
    int size = s.length();

    for(int i = 0; i < size; i++) 
    {
        char ch = s[i];
        if(!isdigit(ch)) 
            result = false;
    }

    return result;
}

int main(
    int argc, 
    char const *argv[]
){
    // create loader instance
    loader ld = loader();

    // validation command line arguments
    if(argc != NUM_ARGS)
    {
        cerr << "ERROR:\t" << "Program must be run in format: ./" << SCHEDULING_ALGO << " <quantum> <datafile>" << endl;
    }
    else if(!isNumber(argv[1]))
    {
        cerr << "ERROR:\t" << "Quantum must be a number." << endl;
    }
    else if(stoi(argv[1]) <= 0)
    {
        cerr << "ERROR:\t" << "Quantum must be greater than 0." << endl;
    }
    else if(!ld.readFile(argv[1]))
    {
        cerr << "ERROR:\t" << "Failed to read file: " << argv[1] << endl;
    }
    else
    {
        // get pcb's loaded from file
        vector<pcb> all_processes = ld.getPCBList();

        // initialise simulator
        simulator sim = simulator(
            SCHEDULING_ALGO,
            all_processes
        );

        // run simulation then print averages
        sim.run_simulator();
        sim.print_averages();
    }
    
    return EXIT_SUCCESS;
}
