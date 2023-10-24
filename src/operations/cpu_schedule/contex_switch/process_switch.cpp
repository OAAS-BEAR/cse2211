#include "../../../utils/timer_util.h"
#include <numeric>
#include <x86intrin.h> // for rdtsc
using namespace std;


void switchProcess(){
    uint64_t start, end;
    pid_t pid = fork();
    int pipefd[2];
    char buf = 'a';
    int ret;
    vector<unsigned long> diff;

    for (int i = 0; i < 10; ++i){
        if (pid < 0){
            cout << "Fork Fail!"<<endl;
        }
        if (pid == 0){
            //child process   
            end = __rdtsc();     
            ret = read(pipefd[0], &buf, 1);     
            exit(0);

        }else{
            
            ret = write(pipefd[1], &buf, 1);
            start = __rdtsc();
            
            
        }
        cout<< end << " " <<start <<endl;
        diff.push_back(end - start);
    }
    cout << "process switch time: " << double(std::accumulate(diff.begin(), diff.end(), 0)) / diff.size()<<endl;

}




int main(){
    setPriority(-20);
    switchProcess();
    return 0;
}