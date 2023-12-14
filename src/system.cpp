#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

/*You need to complete the mentioned TODOs in order to satisfy the rubric criteria "The student will be able to extract and display basic data about the system."

You need to properly format the uptime. Refer to the comments mentioned in format. cpp for formatting the uptime.*/

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
    Process process;
    Processor processor;
    // Check all available pids
    vector<int> pids = LinuxParser::Pids();
    for(long unsigned int i = 0; i < pids.size();i++){
        //Update pid
        process.SetPid(pids[i]);
        //Update user
        string uid = LinuxParser::Uid(pids[i]);
        process.SetUser(LinuxParser::User(uid));
        
        //Update cpu utilization
        auto uptime = LinuxParser::UpTime();
        
        auto cpuUtilizationPID = processor.Utilization_Processes(pids[i], uptime);
        
        process.SetCpuUtilization(cpuUtilizationPID);

        //Update ram
        process.SetRam(LinuxParser::Ram(pids[i]));
        //Update time
        process.SetUpTime(LinuxParser::UpTime(pids[i]));
        //Update command
        process.SetCommand(LinuxParser::Command(pids[i]));
        //add this process to the vector of processes
        processes_.push_back(process);
    }

    return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    return LinuxParser::Kernel(); 
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization(); 
}

// TODO: Return the operating system name
std::string System::OperatingSystem() { 
    return LinuxParser::OperatingSystem();
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { 
    return LinuxParser::TotalProcesses(); 
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { 
    return LinuxParser::UpTime(); 
}
