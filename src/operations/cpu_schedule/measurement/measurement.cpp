#include "timer_util.h"


namespace CPU_M {
    const size_t numIteration = 100;
}

int main(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    timer_start;
    timer_end;
    unsigned long duration = getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("duration: %lu\n", duration);
    return 0;
}