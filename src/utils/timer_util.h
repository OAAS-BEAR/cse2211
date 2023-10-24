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
#include <math.h>
#include <numeric>

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

double MEAN(std::vector<unsigned long> durations){
    return double(std::accumulate(durations.begin(),durations.end(),0.0)/durations.size());

}
double STD(std::vector<unsigned long> durations){
    int loop_num=durations.size();
    double variance=0;
    double mean=MEAN(durations);
    for(int i=0;i<loop_num;i++){
        variance+=(durations[i]-mean)*(durations[i]-mean);
    }
    variance=variance/loop_num;
    return sqrt(variance);
}
