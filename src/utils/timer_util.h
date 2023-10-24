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


const int MAXPRIORITY = -20;
const int ITERATIONS = 10000;


unsigned long long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
#define timer_start \
    asm volatile ("rdtsc\n\t" \
		  "mov %%rdx, %0\n\t" \
		  "mov %%rax, %1\n\t" \
		  : "=r" (cycles_high0), "=r" (cycles_low0));

    /* code to measure */
#define timer_end \
    asm volatile ("rdtsc\n\t" \
		  "mov %%rdx, %0\n\t" \
		  "mov %%rax, %1\n\t" \
		  : "=r" (cycles_high1), "=r" (cycles_low1));


void setPriority(int priority=MAXPRIORITY){
    pid_t pid = getpid();
    int older_priority = getpriority(PRIO_PROCESS, pid);

    int ret = setpriority(PRIO_PROCESS, pid, priority);

    int current_priority = getpriority(PRIO_PROCESS, pid);
    std::cout << "Desired Priority: " << priority << ", "
          << "Old Priority: " << older_priority << ", "
          << "Current Priority: " << current_priority << std::endl;
    assert(priority == current_priority);

    
}

unsigned long long getTimeDiff(unsigned long long cycles_high0, unsigned long long cycles_low0, unsigned long long cycles_high1, unsigned long long cycles_low1){
        unsigned long long start = ((unsigned long long)cycles_high0 << 32) | cycles_low0;
        unsigned long long end = ((unsigned long long)cycles_high1 << 32) | cycles_low1;
        unsigned long long duration = end - start;
        return duration;
}