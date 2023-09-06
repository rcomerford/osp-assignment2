#include <string>

#ifndef TYPES_H
#define TYPES_H

// Renamed some types so that they are more meaningful.
namespace osp2023
{
    // Renamed 64-bit int for time.
    using time_type = long long;

    // Renamed regular int for process ID.
    using id_type = int;

    // Constant used to initialise a time to not having been set.
    extern constexpr time_type time_not_set = -1;
}

#endif // TYPES_H