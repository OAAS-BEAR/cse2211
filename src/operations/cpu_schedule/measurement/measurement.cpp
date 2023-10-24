#include "timer_util.h"


namespace CPU_M {
    const size_t numIteration = 10000;
}

int main(){
    unsigned long long start, end;
    unsigned long long duration{0};
    
    for(int i = 0; i < CPU_M::numIteration; ++i){
        setPriority();
        start = __rdtsc();
        //Empty code
        end = __rdtsc();
        duration += end - start;
    }

    std::cout<<"Average measurement overhead: "<<static_cast<double>(duration)/CPU_M::numIteration<<std::endl;
    return 0;
}