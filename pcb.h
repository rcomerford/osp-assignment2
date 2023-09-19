#include <iostream>
#include "types.h"

#ifndef PCB_H
#define PCB_H

using namespace osp2023;

class pcb 
{
    private:

        // Unique process ID.
        id_type id;

        // Total time a process/job should run for.
        time_type total_time;

        // Time used so far for this process.
        time_type time_used;

        // Time process has spent waiting for CPU.
        time_type total_wait_time;

        // Time process was last on the CPU.
        time_type last_on_cpu;

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

};

#endif // PCB_H