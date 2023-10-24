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


unsigned long getTimeDiff(unsigned long cycles_high0, unsigned long cycles_low0, unsigned long cycles_high1, unsigned long cycles_low1){
        unsigned long start = ((unsigned long long)cycles_high0 << 32) | cycles_low0;
        unsigned long end = ((unsigned long long)cycles_high1 << 32) | cycles_low1;
        unsigned long duration = end - start;
        return duration;
}