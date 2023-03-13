#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { 
    return pid_; 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return 0; }

// TODO: Return the command that generated this process
string Process::Command() { 
    return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { 
    return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() { 
    return user_; 
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return uptime_; 
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }

void Process::SetPid(int pid){
    pid_=pid;
}

void Process::SetUser(std::string user){
    user_ = user;
}

void Process::SetCommand(std::string command){
    command_ = command;
}

void Process::SetCpuUtilization(float cpu_utilization){
    cpu_utilization_ = cpu_utilization;
}

void Process::SetRam(std::string ram){
    ram_ = ram;
}

void Process::SetUpTime(long int uptime){
    uptime_ = uptime;
}