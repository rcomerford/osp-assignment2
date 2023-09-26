#ifndef SIM_H
#define SIM_H

#include "types.h"
#include "pcb.h"
#include <deque>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

#define FIFO "fifo"
#define SJF "sjf"
#define RR "rr"

using std::deque;
using std::setw;
using std::string;
using std::min_element;
using std::distance;
using std::begin;
using std::rotate;
using std::runtime_error;

using namespace osp2023;

class simulator
{
    protected:

        /**
         * Queue of processes (PCBs) waiting to be run.
        */
        deque<pcb*> ready_queue;

        /**
         * The time quantum to use for rr.
        */
        time_type quantum;

        /**
         * Stats tracking for all processes.
        */
        int num_processes;
        time_type running_waiting;
        time_type total_turnaround;
        time_type total_waiting;
        time_type total_response;

        /**
         * Simulates "running" the process defined by the given PCB.
         * Returns the time used by the proccess in the current burst.
        */
        time_type run_process(
            pcb* process,
            const time_type& QUANTUM
        );

    public:

        /**
         * Constructors, for fifo/sjf and rr.
        */     
        simulator(const deque<pcb*>& PCB_LIST);
        simulator(
            const deque<pcb*>& PCB_LIST,
            const time_type& QUANTUM
        );

        /**
         * Run the main loop, asking the scheduler for the id of the next process.
         * Implemented by each of the child classes.
        */
        void run_simulator();

        /**
         * Print functions.
        */
        void print_header();
        void print_averages();
        
};

#endif // SIM_H