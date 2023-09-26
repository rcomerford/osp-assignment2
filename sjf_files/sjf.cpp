#include "sjf.h"

void sjf::run_simulator()
{
    print_header();
    time_type curr_time = 0;

    while(ready_queue.size() > 0)
    {
        // ask the current algorithm what the index of the next process is
        int next_index = sjf_schedule();

        // get next process (& iterator) from index
        pcb* curr_process = ready_queue.at(next_index);
        auto curr_iterator = ready_queue.begin() + next_index;

        // if first time process has CPU, record response time
        if(curr_process->get_time_used() == 0)
            curr_process->set_response_time(curr_time);

        // "run" process  for its entire burst time
        time_type time_used = run_process(curr_process, curr_process->get_burst_time());

        // add time used by process to curr_time
        curr_time += time_used;

        // calculate stats
        curr_process->calculate_total_wait_time(curr_time);
        curr_process->calculate_turnaround_time(curr_time);

        // record all stats to totals
        total_turnaround += curr_process->get_turnaround_time();
        total_waiting += curr_process->get_total_wait_time();
        total_response += curr_process->get_response_time();

        // print details
        curr_process->print_details();

        // remove process from ready queue
        ready_queue.erase(curr_iterator);
    }
}

int sjf::sjf_schedule()
{ 
    // always run the first (0th) job in the ready queue
    // same as fifo. queue is sorted in sjf main file.
    return 0;
}