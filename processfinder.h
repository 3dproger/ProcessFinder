#ifndef PROCESSFINDER_H
#define PROCESSFINDER_H

#include "ProcessFinder_global.h"

extern "C" __declspec(dllexport) double pf_is_process_running_by_name_a(const char* processName); // 1 - found, 0 - not found

#endif // PROCESSFINDER_H
