#include <string>

#include "format.h"
#include <iomanip>

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    long int sec, minutes,hours;
    hours=seconds/3600;
    minutes=(seconds%3600)/60;
    sec=(seconds%3600)%60;
    std::ostringstream stream;
    stream << std::setw(2) << std::setfill('0') << to_string(hours) << ":" 
        << std::setw(2) << std::setfill('0') << to_string(minutes) << ":"
        << std::setw(2) << std::setfill('0') << to_string(sec);
    return stream.str();

    //return string(to_string(hours)+":" + to_string(minutes)+ ":"+ to_string(sec));
}