#include "../../../utils/timer_util.h"
#include <numeric>
#include <x86intrin.h> // for rdtsc
using namespace std;

const int iter = 100000;
int main(){

    uint64_t start = __rdtsc();
    for(int i = 0; i < iter ; ++i){}
    uint64_t end = __rdtsc();
    cout << (end - start) <<endl;
    uint64_t duration = end - start;
    cout << static_cast<double>(duration) / iter<<endl;

    return 0;
}