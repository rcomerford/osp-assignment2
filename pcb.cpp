#include "types.h"
#include "pcb.h"

using namespace osp2023;

pcb::pcb(
    const int& PROCESS_ID,
    const int& BURST_TIME
){
    id = PROCESS_ID;
    total_time = BURST_TIME;
}