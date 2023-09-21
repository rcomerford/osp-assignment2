#ifndef SIM_H
#define SIM_H

#include "types.h"
#include "pcb.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

#define FIFO "fifo"
#define SJF "sjf"
#define RR "rr"

using std::vector;
using std::find_if;
using std::setw;
using std::string;

using namespace osp2023;

class simulator
{
    private:

        /**
         * The scheduling algorithm to use.
        */
       string scheduling_algo;

        /**
         * Queue of processes (PCBs) waiting to be run.
        */
        vector<pcb> ready_queue;

        /**
         * Stats tracking for all processes.
        */
        int num_processes;
        time_type running_waiting;
        time_type total_turnaround;
        time_type total_waiting;
        time_type total_response;

    public:

        /**
         * Constructor which copies parsed PCBs into the ready_queue.
        */
        simulator(
            const string SCHEDULING_ALGO,
            const vector<pcb> PCB_LIST
        );

        /**
         * Run the main loop, asking the scheduler for the id of the next process.
         * Overridden by rr derived class only.
         * Returns a boolean denoting success.
        */
        bool run_simulator();

        /**
         * Scheduling algorithms, each returns the id of the next process.
        */
        int fifo_schedule();
        int sjf_schedule();
        int rr_schedule();

        /**
         * Print functions.
        */
        void print_header();
        void print_averages();
        
};

#endif // SIM_H