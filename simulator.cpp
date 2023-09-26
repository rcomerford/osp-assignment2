#include "simulator.h"

simulator::simulator(const deque<pcb*>& PCB_LIST)
{
    ready_queue = PCB_LIST;
    num_processes = ready_queue.size();
    total_turnaround = 0;
    total_waiting = 0;
    total_response = 0;
}

simulator::simulator(
    const deque<pcb*>& PCB_LIST,
    const time_type& QUANTUM
) : simulator::simulator(PCB_LIST)
{
    quantum = QUANTUM;
}

time_type simulator::run_process(
    pcb* process,
    const time_type& QUANTUM
){
    // cpu time used for the current time slice
    time_type time_used;

    // if process will finish in the current time slice, use only the remaining time
    if(process->get_time_used() + QUANTUM > process->get_burst_time())
        time_used = process->get_burst_time() - process->get_time_used();
    else
        time_used = QUANTUM;

    // add to total CPU time
    process->add_to_time_used(time_used);

    return time_used;
}

void simulator::print_header()
{
    cout << setw(WIDTH_OFFSET) << "Process ID";
    cout << setw(WIDTH_OFFSET) << "Burst Time";
    cout << setw(WIDTH_OFFSET) << "Wait Time";
    cout << setw(WIDTH_OFFSET) << "Turnaround Time";
    cout << setw(WIDTH_OFFSET) << "Response Time";
    cout << endl;
}

void simulator::print_averages()
{
    float average_turnaround = total_turnaround / (float)num_processes;
    float average_waiting = total_waiting / (float)num_processes;
    float average_response = total_response / (float)num_processes;

    cout << endl;

    cout << setw(WIDTH_OFFSET) << "";
    cout << setw(WIDTH_OFFSET) << "";
    cout << setw(WIDTH_OFFSET) << "Wait Time";
    cout << setw(WIDTH_OFFSET) << "Turnaround Time";
    cout << setw(WIDTH_OFFSET) << "Response Time";
    cout << endl;

    cout << setw(WIDTH_OFFSET) << "";
    cout << setw(WIDTH_OFFSET) << "Total";
    cout << setw(WIDTH_OFFSET) << total_waiting;
    cout << setw(WIDTH_OFFSET) << total_turnaround;
    cout << setw(WIDTH_OFFSET) << total_response;
    cout << endl;

    cout << setw(WIDTH_OFFSET) << "";
    cout << setw(WIDTH_OFFSET) << "Average";
    cout << setw(WIDTH_OFFSET) << average_waiting;
    cout << setw(WIDTH_OFFSET) << average_turnaround;
    cout << setw(WIDTH_OFFSET) << average_response;
    cout << endl;
}
