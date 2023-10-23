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


unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
#define timer_start \
    asm volatile ("cpuid\n\t" \
		  "rdtsc\n\t" \
		  "mov %%edx, %0\n\t" \
		  "mov %%eax, %1\n\t" \
		  : "=r" (cycles_high0), "=r" (cycles_low0) \
		  :: "%rax", "%rbx", "%rcx", "%rdx");

    /* code to measure */
#define timer_end \
    asm volatile ("rdtscp\n\t" \
		  "mov %%edx, %0\n\t" \
		  "mov %%eax, %1\n\t" \
		  "cpuid\n\t" \
		  : "=r" (cycles_high1), "=r" (cycles_low1) \
		  :: "%rax", "%rbx", "%rcx", "%rdx");


unsigned long getTimeDiff(unsigned long cycles_high0, unsigned long cycles_low0, unsigned long cycles_high1, unsigned long cycles_low1){
        unsigned long start = ((unsigned long long)cycles_high0 << 32) | cycles_low0;
        unsigned long end = ((unsigned long long)cycles_high1 << 32) | cycles_low1;
        unsigned long duration = end - start;
        return duration;
}

void setPriority(int priority){
    pid_t pid = getpid();
    int older_priority = getpriority(PRIO_PROCESS, pid);
    int ret;

    ret = nice(priority); // Adjust the priority by the difference

    assert(priority == ret);

    int current_priority = getpriority(PRIO_PROCESS, pid);
    printf("older priority: %d, current priority: %d\n", older_priority, current_priority);
}