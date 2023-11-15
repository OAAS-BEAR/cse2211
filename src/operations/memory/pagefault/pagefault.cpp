#include <iostream>
#include <stdio.h>
#include<sys/mman.h>
#include "../../../utils/timer_util.h"
#include <unistd.h>
#include<sys/wait.h>
#include <fcntl.h>
using namespace std;
int loop=500;
int pagesize=4096;
int main(){
    setPriority(-20);
    
    int fd;
    fd=open("/root/CSE221_Project/src/operations/memory/pagefault/test2.txt",O_RDWR);
    if(fd==-1){
        cout<<"can not open file\n";
    }
    else{
        cout<<fd;
        cout<<"right file\n";
    }
    char a;
    char* fileaddr=(char*)mmap(NULL,4096*500*200,PROT_READ,MAP_SHARED,fd,0);
    unsigned long offset=0;
    vector<unsigned long>durations;
    for (int i=0;i<loop;i++){
        double start = __rdtsc();
        a=*(fileaddr+offset);
        double end= __rdtsc();
        offset+=4096*200;
        durations.push_back((end - start)/10000);
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling getppid:"<<mean*10000<<" std:"<<10000*standard<<endl;
}