#include "simulator.h"

simulator::simulator(
    const string SCHEDULING_ALGO,
    const vector<pcb> PCB_LIST
){
    // the algorithm to use to get next process
    scheduling_algo = SCHEDULING_ALGO;

    // add all pcb's into the ready queue
    ready_queue = PCB_LIST;

    // record number of processes given to sim
    num_processes = ready_queue.size();

    // initialise cumulative stats
    running_waiting = 0;
    total_turnaround = 0;
    total_waiting = 0;
    total_response = 0;
}

bool simulator::run_simulator()
{
    print_header();

    while(ready_queue.size() > 0)
    {
        // ask the current scheduler for next process to run
        int NEXT_INDEX;

        // get the index of the next process to run
        if(scheduling_algo.compare(FIFO) == 0)
        {
            NEXT_INDEX = fifo_schedule();
        }
        else if(scheduling_algo.compare(SJF) == 0)
        {
            NEXT_INDEX = sjf_schedule();
        }
        else if(scheduling_algo.compare(RR) == 0)
        {
            NEXT_INDEX = rr_schedule();
        }
        else
        {
            return false;
        }

        // get the pcb for the process to be run
        pcb CURR_PROCESS = ready_queue[NEXT_INDEX];

        // "run" the process, details automatically print once process completes
        CURR_PROCESS.run(
            CURR_PROCESS.get_burst_time(),
            running_waiting
        );

        // keep track of stats for averages
        total_waiting += running_waiting;
        total_turnaround += (running_waiting + CURR_PROCESS.get_burst_time());
        total_response += CURR_PROCESS.get_total_wait_time();
        running_waiting += CURR_PROCESS.get_burst_time();

        // remove process from ready queue once "executed"
        ready_queue.erase(ready_queue.begin() + NEXT_INDEX);
    }

    return true;
}

int simulator::fifo_schedule()
{ 
    // always run the first job in the ready queue
    return 0; 
}

int simulator::sjf_schedule()
{ 
    // TODO sjf
    return -1; 
}

int simulator::rr_schedule()
{ 
    // TODO rr
    return -1; 
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
