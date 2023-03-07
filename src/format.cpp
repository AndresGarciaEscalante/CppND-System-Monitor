#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    long int sec, minutes,hours;
    hours=(int)(seconds/3600);
    minutes=((int)(seconds/60))%60;
    sec=(int)(seconds%60);
    return string(to_string(hours)+":" + to_string(minutes)+ ":"+ to_string(sec));
}