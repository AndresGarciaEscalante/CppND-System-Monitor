#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "linux_parser.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               // TODO: See src/process.cpp
  void SetPid(int pid);
  std::string User();                      // TODO: See src/process.cpp
  void SetUser(std::string user);
  std::string Command();                   // TODO: See src/process.cpp
  void SetCommand(std::string command);
  float CpuUtilization();                  // TODO: See src/process.cpp
  void SetCpuUtilization(float cpu_utilization);
  std::string Ram();                       // TODO: See src/process.cpp
  void SetRam(std::string ram);
  long int UpTime();                       // TODO: See src/process.cpp
  void SetUpTime(long int uptime);
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
  int pid_;
  std::string user_;
  std::string command_;
  float cpu_utilization_;
  std::string ram_;
  long int uptime_;
};

#endif