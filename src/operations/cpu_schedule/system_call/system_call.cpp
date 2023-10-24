#include <iostream>
#include <stdio.h>
#include "../../../utils/timer_util.h"
#include <unistd.h>
#include<sys/wait.h>
using namespace std;
int loop=1000;
void test_system_call(){
    int pid=fork();
    if(pid>0){
        wait(NULL);
    }
    else{
        vector<unsigned long>durations;
        for(int i=0;i<loop;i++){
            unsigned long start, end;
            start = __rdtsc();
            getppid();
            end = __rdtsc();
            durations.push_back((end - start));
        }
        double mean=MEAN(durations);
        double standard=STD(durations);
        cout<<"The mean cycles needed for calling getppid:"<<mean<<" std:"<<standard<<endl;
    }

}
int main(){
    setPriority(-20);
    test_system_call();
    return 0;
}