#include <iostream>
#include <stdio.h>
#include "timer_util.h"
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
            unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
            timer_start;
            getppid();
            timer_end;
            unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
            durations.push_back(duration);
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