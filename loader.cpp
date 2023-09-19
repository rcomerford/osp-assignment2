#include "loader.h"

#define FILE_DELIM ','

// global variables, used for debugging
extern bool IS_DEBUG_MODE;

loader::~loader()
{
    // delete pointers then clear vector

    for(int i = 0; i < pcb_list.size(); i++)
        delete (pcb_list[i]);

    pcb_list.clear();
}

bool loader::init(
    const string& FILE_NAME
){

    if(IS_DEBUG_MODE) cout << "LOADER:\tAttempting load with file name: " << FILE_NAME << endl;

    // attempt to open file and return status
    in.open(FILE_NAME);
    if(in)
    {
        // read each line
        try
        {
            // read each line and parse
            string line = "";
            while(getline(in, line))
                pcb_list.push_back(parseLine(line));
        }
        catch(const exception& e)
        {
            if(IS_DEBUG_MODE) cout << "LOADER:\tFailed to read file." << endl;
            if(IS_DEBUG_MODE) cerr << "LOADER:\t" << e.what() << endl;
        }
    }
    else
    {
        // return fail status if file cannot be opened
        if(IS_DEBUG_MODE) cout << "LOADER:\tFailed to open file." << endl;
    }

    return false;
}

vector<pcb*> loader::getPCBList()
{
    return pcb_list;
}


pcb* loader::parseLine(
    const string &LINE
){
    const vector<string> SPLIT_LINE = splitString(LINE, FILE_DELIM);

    // pcb variables
    // exceptions here caught by init()
    const int PROCESS_ID = stoi(SPLIT_LINE[0]);
    const int BURST_TIME = stoi(SPLIT_LINE[1]);

    pcb* new_pcb = new pcb(
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