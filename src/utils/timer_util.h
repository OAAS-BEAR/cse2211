#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>
#include<math.h>
#include<vector>
#include<numeric>
#include <x86intrin.h> 

/*
unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
#define timer_start \
    asm volatile ("cpuid\n\t" \
          "rdtsc\n\t" \
		  "mov %%rdx, %0\n\t" \
		  "mov %%rax, %1\n\t" \
		  : "=r" (cycles_high0), "=r" (cycles_low0)\
          :: "%rax","%rbx","%rcx","%rdx");

 
#define timer_end \
    asm volatile ("rdtscp\n\t" \
		  "mov %%rdx, %0\n\t" \
		  "mov %%rax, %1\n\t" \
          "cpuid\n\t" \
		  : "=r" (cycles_high1), "=r" (cycles_low1) \
          :: "%rax","%rbx","%rcx","%rdx");


unsigned long getTimeDiff(unsigned long cycles_high0, unsigned long cycles_low0, unsigned long cycles_high1, unsigned long cycles_low1){
        unsigned long start = ((unsigned long long)cycles_high0 << 32) | cycles_low0;
        unsigned long end = ((unsigned long long)cycles_high1 << 32) | cycles_low1;
        unsigned long duration = end - start;
        return duration;
}
*/

const int MAXPRIORITY = -20;

void setPriority(int priority=MAXPRIORITY){
    pid_t pid = getpid();
    int older_priority = getpriority(PRIO_PROCESS, pid);

    int ret = setpriority(PRIO_PROCESS, pid, priority);
    std::cout << "return value:"<<ret<< std::endl;
    int current_priority = getpriority(PRIO_PROCESS, pid);
     std::cout << "Desired Priority: " << priority << ", "
           << "Old Priority: " << older_priority << ", "
          << "Current Priority: " << current_priority << std::endl;
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
