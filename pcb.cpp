#include "types.h"
#include "pcb.h"

using namespace osp2023;

pcb::pcb(
    const int& PROCESS_ID,
    const int& BURST_TIME
){
    id = PROCESS_ID;
    burst_time = BURST_TIME;
    time_used = 0;
    total_wait_time = 0;
    response_time = -1;
}

void pcb::run(
    const time_type& QUANTUM,
    const time_type& WAIT_ADD
){
    time_used += QUANTUM;
    total_wait_time += WAIT_ADD;

    // set response time to wait time on the first run
    if(response_time == -1)
        response_time = WAIT_ADD;

    // automatically print details once finished running
    if(time_used == burst_time)
        print();
}

void pcb::print() const
{
    cout << setw(WIDTH_OFFSET) << get_id();
    cout << setw(WIDTH_OFFSET) << get_burst_time();
    cout << setw(WIDTH_OFFSET) << get_total_wait_time();
    cout << setw(WIDTH_OFFSET) << (get_total_wait_time() + get_burst_time());
    cout << setw(WIDTH_OFFSET) << get_response_time();
    cout << endl;
}

id_type pcb::get_id() const
{
    return id;
}

time_type pcb::get_burst_time() const
{
    return burst_time;
}

time_type pcb::get_time_used() const
{
    return time_used;
}

time_type pcb::get_total_wait_time() const
{
    return total_wait_time;
}

time_type pcb::get_response_time() const
{
    return response_time;
}