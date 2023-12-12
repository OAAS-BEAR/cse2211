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
double read_files_sequential(int fd,int filepage,int processNum){
    char*buffer;
    posix_memalign((void**)&buffer,pagesize,pagesize);
    int * array=(int *) malloc(filepage*sizeof(int));
    for (int i=0;i<filepage;i++){
        array[i]=i;
    }

    vector<unsigned long>durations;
    for(int i=0;i<filepage;i++){
        int page=array[i];
        /*off_t r=lseek(fd,page*pagesize*100,SEEK_SET);
        if(r==-1){
            cout<<"lseek failed, please check code\n";
            return 0;
        }
        */
 
        double start = __rdtsc();
        int nums=read(fd,buffer,pagesize);
        double end= __rdtsc();
        durations.push_back((end - start)/10000);
        if(nums!=pagesize){
            cout<<"read size is not 4096 Bytes"<<nums;
        }
    }

    double mean=MEAN(durations);
    double standard=STD(durations);
    //cout<<"The mean cycles needed for process_num"<<processNum<<":"<<mean*10000<<" std:"<<10000*standard<<endl;
    
    return mean;
}
int main(){
    setPriority(-20);
    int processNums[5]={2,4,6,8,10};
    int n=5;
    int pipe_fd[2];
    pipe(pipe_fd);
    
    int filenum=0;
    for(int i=0;i<n;i++){  
        double means=0;
        
        for(int j=1;j<=processNums[i];j++){
            filenum+=1;
            pid_t pid=fork();
            if(pid==0){
                
                std::string filename ="/home/ubuntu/local/file_" + std::to_string(filenum)+".txt";
                int fd=open(filename.c_str(),O_RDONLY|O_DIRECT); //read from disk to disable cache
                if(fd==-1){
                    cout<<"can not open file\n";
                }
                int filepage=64*1024/4; //64MB
                double mean=read_files_sequential(fd, filepage,processNums[i]);
                
                write(pipe_fd[1], &mean, sizeof(double));
                posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED);
                close(fd);
                exit(0);
            }
        }
        
        for (int k=0;k<processNums[i];k++){
            wait(NULL);
            double mean=0;
            read(pipe_fd[0], &mean, sizeof(double));
            //cout<<mean<<endl;
            means+=mean;

        }

        cout<<"The mean cycles needed for process_num"<<processNums[i]<<":"<<(means/processNums[i])*10000<<endl;


        }


    return 0;


}