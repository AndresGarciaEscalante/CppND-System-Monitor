#include "processor.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::stof;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    // Store Actual Values for CPU utilization
    float ac_user, ac_nice, ac_system, ac_idle, ac_iowait, ac_irq, ac_softirq, ac_steal, ac_guest, ac_guest_nice;
    // Additional variables
    float PrevIdle, Idle, PrevNonIdle, NonIdle, PrevTotal, Total;
    float totald, idled, cpu_percentage;
    
    // Retrieve the information
    vector<string> cpu = LinuxParser::CpuUtilization();
    ac_user = stof(cpu[0]);
    ac_nice = stof(cpu[1]);
    ac_system = stof(cpu[2]); 
    ac_idle = stof(cpu[3]);
    ac_iowait = stof(cpu[4]);
    ac_irq = stof(cpu[5]);
    ac_softirq = stof(cpu[6]);
    ac_steal = stof(cpu[7]);
    ac_guest = stof(cpu[8]);
    ac_guest_nice= stof(cpu[9]);

    // Calculate the CPU utilization
    PrevIdle = prev_idle + prev_iowait;
    Idle = ac_idle + ac_iowait;

    PrevNonIdle = prev_user + prev_nice + prev_system + prev_irq + prev_softirq + prev_steal;
    NonIdle = ac_user + ac_nice + ac_system + ac_irq + ac_softirq + ac_steal;

    PrevTotal = PrevIdle + PrevNonIdle;
    Total = Idle + NonIdle;

    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;

    cpu_percentage = (totald - idled)/totald*100;

    prev_user = ac_user;
    prev_nice = ac_nice;
    prev_system = ac_system;
    prev_idle = ac_idle;
    prev_iowait = ac_iowait;
    prev_irq = ac_irq; 
    prev_softirq = ac_softirq;
    prev_steal = ac_steal; 
    prev_guest = ac_guest;
    prev_guest_nice = ac_guest_nice;
    
    return cpu_percentage; 
}