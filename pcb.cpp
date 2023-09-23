#include "types.h"
#include "pcb.h"

using namespace osp2023;

pcb::pcb(
    const int& PROCESS_ID,
    const int& BURST_TIME
){
    id = PROCESS_ID;
    burst_time = BURST_TIME;
    total_time_used = 0;
    total_wait_time = -1;
    turnaround_time = -1;
    response_time = -1;
}

void pcb::print_details() const
{
    cout << setw(WIDTH_OFFSET) << get_process_id();
    cout << setw(WIDTH_OFFSET) << get_burst_time();
    cout << setw(WIDTH_OFFSET) << get_total_wait_time();
    cout << setw(WIDTH_OFFSET) << get_turnaround_time();
    cout << setw(WIDTH_OFFSET) << get_response_time();
    cout << endl;
}

void pcb::set_response_time(const time_type& RESPONSE_TIME)
{
    response_time = RESPONSE_TIME;
}

void pcb::add_to_time_used(const time_type& TIME_USED)
{
    total_time_used += TIME_USED;
}

void pcb::calculate_total_wait_time(const time_type& CURRENT_TIME)
{
    total_wait_time = CURRENT_TIME - total_time_used;
}

void pcb::calculate_turnaround_time(const time_type& CURRENT_TIME)
{
    turnaround_time = (CURRENT_TIME - total_time_used) + burst_time;
}

id_type pcb::get_process_id() const
{
    return id;
}

time_type pcb::get_burst_time() const
{
    return burst_time;
}

time_type pcb::get_total_wait_time() const
{
    return total_wait_time;
}

time_type pcb::get_turnaround_time() const
{
    return turnaround_time;
}

time_type pcb::get_response_time() const
{
    return response_time;
}

time_type pcb::get_time_used() const
{
    return total_time_used;
}