#include "../../../utils/timer_util.h"
#include <numeric>
#include <x86intrin.h> // for rdtsc
using namespace std;


int main(){
    setPriority(-20);
    uint64_t start, end, duration;
    timer_start;
    for(int i = 0; i < ITERATIONS * ITERATIONS; ++i)
    timer_end;


    start = __rdtsc();
    for(int i = 0; i < ITERATIONS * ITERATIONS ; ++i)
    end = __rdtsc();
    cout << end - start <<endl;
    duration = end - start;


    unsigned long long res = getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    cout << res <<endl;


    cout << double(duration - res) / duration<<endl;

    return 0;
}