#ifndef PCB_H
#define PCB_H

#include "types.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

using namespace osp2023;

class pcb 
{
    private:
    
        // Unique process ID.
        id_type id;

        // Total time the process should run for.
        time_type burst_time;

        // Time used so far for this process.
        time_type total_time_used;

        // Time process has spent waiting for CPU.
        time_type total_wait_time;

        // Time it took for the process to first get on the CPU.
        time_type response_time;

        // Time it took for the process to complete from arrival time.
        time_type turnaround_time;

    public:

        /**
         * Constructor, given arguments from data file.
        */
        pcb(
            const int& PROCESS_ID,
            const int& BURST_TIME
        );

        /**
         * Prints the stats and details of the process.
        */
        void print_details() const;

        /**
         * Modification functions (setters), used by the simulator.
        */
        void add_to_time_used(const time_type& TIME_USED);
        void set_response_time(const time_type& RESPONSE_TIME);
        void calculate_total_wait_time(const time_type& CURRENT_TIME);
        void calculate_turnaround_time(const time_type& CURRENT_TIME);

        /**
         * Getters.
        */
        id_type get_process_id() const;
        time_type get_burst_time() const;
        time_type get_total_wait_time() const;
        time_type get_turnaround_time() const;
        time_type get_response_time() const;
        time_type get_time_used() const;

};

#endif // PCB_H