#ifndef TYPES_H
#define TYPES_H

/**
 * Universal width offset for outputs.
*/
#define WIDTH_OFFSET 25

/**
 * Universal file delimiter.
*/
#define FILE_DELIM ','

/**
 * Renamed  types so that they are more meaningful.
*/
namespace osp2023
{
    // renamed 64-bit int for time.
    using time_type = long long;

    // renamed regular int for process ID.
    using id_type = int;
}

#endif // TYPES_H