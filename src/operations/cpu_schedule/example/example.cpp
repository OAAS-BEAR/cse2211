#include <iostream>
#include "timer_util.h"


int main(){
    std::cout<<" Report from src/operations/cpu_shcedule/exmaple/example.cpp";
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    std::cout<< getTimeDiff(cycles_high0,cycles_low0,cycles_high1,cycles_low1)<<std::endl;
}