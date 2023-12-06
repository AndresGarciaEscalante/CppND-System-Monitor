#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

class Processor {
 public:
  Processor() {     // Constructor
    prev_user = 0.0;
    prev_nice = 0.0;
    prev_system = 0.0;
    prev_idle = 0.0;
    prev_iowait = 0.0;
    prev_irq = 0.0; 
    prev_softirq = 0.0;
    prev_steal = 0.0; 
    prev_guest = 0.0;
    prev_guest_nice = 0.0;
  }

  float Utilization();  // TODO: See src/processor.cpp
  float Utilization_Processes(int pid, long uptime);  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    // Private Variables
    float prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq, prev_steal, prev_guest, prev_guest_nice;
};

#endif