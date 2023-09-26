#include "../simulator.h"

class rr: public simulator
{
    public:

        /**
         * Inherited constructor.
        */     
        rr(const deque<pcb*>& PCB_LIST, const time_type& QUANTUM) : simulator(PCB_LIST, QUANTUM){};

        /**
         * Runs the simulation, manipulating the ready queue.
        */     
        void run_simulator();

        /**
         * Gets index of the next process to be run.
        */     
        int rr_schedule();
};