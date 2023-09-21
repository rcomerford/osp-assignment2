#include "loader.h"

bool loader::readFile(
    const string& FILE_NAME
){
    cout << "LOADER:\tAttempting to load file with name: " << FILE_NAME << endl;

    // attempt to open file and return status
    in.open(FILE_NAME);
    if(in)
    {
        try
        {
            // read each line and parse
            string line = "";
            while(getline(in, line))
                pcb_list.push_back(parseLine(line));
        }
        catch(const exception& e)
        {
            cerr << "LOADER:\tFailed while reading file. Error: " << e.what() << endl;
            return false;
        }
    }

    cout << "LOADER:\tCompleted loading file." << endl;
    return true;
}

vector<pcb> loader::getPCBList()
{
    return pcb_list;
}

pcb loader::parseLine(
    const string &LINE
){
    const vector<string> SPLIT_LINE = splitString(LINE, FILE_DELIM);

    // pcb variables, exceptions here caught by init()
    const int PROCESS_ID = stoi(SPLIT_LINE[0]);
    const int BURST_TIME = stoi(SPLIT_LINE[1]);

    // pcb variables error checking
    if(PROCESS_ID < 0)
        throw std::invalid_argument("invalid process_id");

    if(BURST_TIME < 0)
        throw std::invalid_argument("invalid burst_time");

    pcb new_pcb = pcb(
        PROCESS_ID,
        BURST_TIME
    );

    return new_pcb;
}

vector<string> loader::splitString(
    const string &STRING, 
    const char DELIM
){
    vector<string> output;
    string item;

    // read string as stream to each delim
    stringstream ss(STRING);
    while(getline(ss, item, DELIM)) 
        output.push_back(item);

    return output;
}