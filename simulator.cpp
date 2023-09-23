#include "simulator.h"

simulator::simulator(
    const string& SCHEDULING_ALGO,
    const deque<pcb*>& PCB_LIST,
    const time_type& QUANTUM
){
    scheduling_algo = SCHEDULING_ALGO;
    ready_queue = PCB_LIST;
    quantum = QUANTUM;
    num_processes = ready_queue.size();
    total_turnaround = 0;
    total_waiting = 0;
    total_response = 0;
}

void simulator::run_simulator()
{
    print_header();
    time_type curr_time = 0;

    while(ready_queue.size() > 0)
    {
        // ask the current algorithm what the index of the next process is
        int next_index = 0;

        if(scheduling_algo.compare(FIFO) == 0)
            next_index = fifo_schedule();
        else if(scheduling_algo.compare(SJF) == 0)
            next_index = sjf_schedule();
        else if(scheduling_algo.compare(RR) == 0)
            next_index = rr_schedule();
        else
            throw runtime_error("Invalid scheduling algorithm.");

        // get next process (& iterator) from index
        pcb* curr_process = ready_queue.at(next_index);
        auto curr_iterator = ready_queue.begin() + next_index;

        // if first time process has CPU, record response time
        if(curr_process->get_time_used() == 0)
            curr_process->set_response_time(curr_time);

        // "run" process, either for the quantum or for its entire burst time
        time_type curr_quantum = (quantum == -1) ? curr_process->get_burst_time() : quantum;
        time_type time_used = run_process(curr_process, curr_quantum);

        // add time used by process to curr_time
        curr_time += time_used;

        // if process is completed
        if(curr_process->get_burst_time() == curr_process->get_time_used())
        {
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
        else
        {
            // move to back of ready queue
            rotate(curr_iterator, curr_iterator + 1, ready_queue.end());
        }
    }
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

int simulator::fifo_schedule()
{ 
    // always run the first (0th) job in the ready queue
    return 0; 
}

int simulator::sjf_schedule()
{ 
    // find job with smallest time, could also be achieved by sorting the queue first
    auto min_iter = min_element(
        ready_queue.begin(), 
        ready_queue.end(), 
        [](const pcb* lhs, const pcb* rhs) {
            return (lhs->get_burst_time() < rhs->get_burst_time());
        }
    );

    const int MIN_PCB_INDEX = distance(begin(ready_queue), min_iter);
    return MIN_PCB_INDEX; 
}

int simulator::rr_schedule()
{
    return 0;
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
