#include "../simulator.h"

class sjf: public simulator
{
    public:
    
        /**
         * The time quantum to use for rr.
        */
        time_type quantum;

        /**
         * Inherited constructor.
        */     
        sjf(const deque<pcb*>& PCB_LIST) : simulator(PCB_LIST){};

        /**
         * Runs the simulation, manipulating the ready queue.
        */     
        void run_simulator();

        /**
         * Gets index of the next process to be run.
        */     
        int sjf_schedule();
};