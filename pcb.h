#include <iostream>
#include "types.h"

#ifndef PCB_H
#define PCB_H

/**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/

using namespace osp2023;

class pcb 
{
    // Unique process ID.
    id_type id;

    // Total time a process/job should run for.
    time_type total_time;

    // Time used so far for this process.
    time_type time_used;

    // Time process has spent waiting for CPU.
    time_type total_wait_time;

    // Time process was last on the CPU.
    // TODO add.

    public:
    
        /**
         * The maximum and minimum duration for a system process.
        */
        static constexpr time_type MAX_DURATION = 100;
        static constexpr time_type MIN_DURATION = 10;
};

#endif // PCB_H