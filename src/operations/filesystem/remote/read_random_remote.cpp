#include <iostream>
#include<fstream>
#include <stdio.h>
#include<sys/mman.h>
#include <stdlib.h>
#include "../../../utils/timer_util.h"
#include <unistd.h>
#include<sys/wait.h>
#include <fcntl.h>
using namespace std;
int loop=500;
int pagesize=4096;

int read_files_random(int fd,int filepage){
    char*buffer=(char*)malloc(pagesize);
    int * array=(int *) malloc(filepage*sizeof(int));
    for (int i=0;i<filepage;i++){
        array[i]=i;
    }

    // the following code shuffle the array
    for(int i=filepage-1;i>0;i--){
        int j=rand()%(i+1);
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    vector<unsigned long>durations;
    double start = __rdtsc();
    for(int i=0;i<filepage;i++){
        int page=array[i];
        off_t r=lseek(fd,page*pagesize,SEEK_SET);
        if(r==-1){
            cout<<"lseek failed, please check code\n";
            return 0;
        }

        int nums=read(fd,buffer,pagesize);
        if(nums!=pagesize){
            cout<<"read size is not 4096 Bytes";
        }
    }
    double end= __rdtsc();
    durations.push_back((end - start)/10000);
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for filesize"<<(filepage*4/1024)<<"MB:"<<mean*10000<<" std:"<<10000*standard<<endl;
    
    return 0;
}
int read_files_sequential(int fd,int filepage){
    char*buffer=(char*)malloc(pagesize);
    int * array=(int *) malloc(filepage*sizeof(int));
    for (int i=0;i<filepage;i++){
        array[i]=i;
    }

    vector<unsigned long>durations;
    double start = __rdtsc();
    for(int i=0;i<filepage;i++){
        int page=array[i];
        off_t r=lseek(fd,page*pagesize,SEEK_SET);
        if(r==-1){
            cout<<"lseek failed, please check code\n";
            return 0;
        }

        int nums=read(fd,buffer,pagesize);
        if(nums!=pagesize){
            cout<<"read size is not 4096 Bytes";
        }
    }
    double end= __rdtsc();
    durations.push_back((end - start)/10000);
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for filesize"<<(filepage*4/1024)<<"MB:"<<mean*10000<<" std:"<<10000*standard<<endl;
    
    return 0;
}
int main(){
    setPriority(-20);
    int filesizes[5];
    filesizes[0]=16;
    filesizes[1]=32;
    filesizes[2]=64;
    filesizes[3]=128;
    filesizes[4]=256;
    int n=5;
    for(int i=0;i<n;i++){
        std::string filename ="/home/ubuntu/sharedfiles/file_" + std::to_string(filesizes[i])+"MB.txt";
        int fd=open(filename.c_str(),O_RDONLY| O_DIRECT); //read from disk to disable cache
        if(fd==-1){
            cout<<"can not open file\n";
        }

        int filepage=filesizes[i]*1024/4;
        read_files_random(fd, filepage);
        close(fd);

    }


}