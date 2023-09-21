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
        time_type time_used;

        // Time process has spent waiting for CPU.
        time_type total_wait_time;

        // Time it took for the process to first get on the CPU.
        time_type response_time;

    public:

        /**
         * The maximum and minimum duration for a system process.
        */
        static constexpr time_type MAX_DURATION = 100;
        static constexpr time_type MIN_DURATION = 10;

        /**
         * PCB constructor given arguments from data file.
        */
        pcb(
            const int& PROCESS_ID,
            const int& BURST_TIME
        );

        /**
         * 
        */
        void run(
            const time_type& QUANTUM,
            const time_type& WAIT_ADD
        );

        /**
         * Prints the stats and details of the process (once finished).
        */
        void print() const;

        /**
         * Getters.
        */
        id_type   get_id() const;
        time_type get_burst_time() const;
        time_type get_time_used() const;
        time_type get_total_wait_time() const;
        time_type get_response_time() const;

};

#endif // PCB_H