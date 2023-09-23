#ifndef LOADER_H
#define LOADER_H

#include "types.h"
#include "pcb.h"
#include <deque>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using std::vector;
using std::deque;
using std::string;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::exception;
using std::invalid_argument;

using namespace osp2023;

class loader
{
    private:

        /**
         * Holds the read PCB's.
        */
        deque<pcb*> pcb_list;

        /**
         * Reads the given FILE_NAME.
        */
        ifstream in;
    
        /**
         * Converts a string containing <> to a pcb.
         * Returns a pointer to the pcb type for the given string.
        */
        pcb* parseLine(
            const string &LINE
        );

        /**
         * Splits a string by the DELIM character.
         * Returns a vector of the split strings, sans DELIM.
        */
        vector<string> splitString(
            const string& STRING, 
            const char& DELIM
        );

    public:

        /**
         * Con/destructor.
         * Deals with the pcb_list pointers.
        */
        loader();
        ~loader();

        /**
         * Initialise file reading. Takes a file name.
         * Returns a boolean denoting success. 
        */
        bool readFile(
            const string& FILE_NAME
        );

        /**
         * Returns the vector of PCB's read by init().
        */
        deque<pcb*> getPCBList();
        
};

#endif // LOADER_H