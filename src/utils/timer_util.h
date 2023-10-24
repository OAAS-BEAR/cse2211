#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <x86intrin.h> // for rdtsc


const int MAXPRIORITY = -20;
const int ITERATIONS = 1000;



// set priority for current process
void setPriority(int priority=MAXPRIORITY){
    pid_t pid = getpid();
    int older_priority = getpriority(PRIO_PROCESS, pid);

    int ret = setpriority(PRIO_PROCESS, pid, priority);

    int current_priority = getpriority(PRIO_PROCESS, pid);
    // std::cout << "Desired Priority: " << priority << ", "
    //       << "Old Priority: " << older_priority << ", "
    //       << "Current Priority: " << current_priority << std::endl;
    assert(priority == current_priority);

    
}
