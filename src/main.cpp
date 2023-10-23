#include <iostream>
#include "timer_util.h"

// This is just a example file.
int main(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    std::cout<< getTimeDiff(cycles_high0,cycles_low0,cycles_high1,cycles_low1)<<std::endl;
}