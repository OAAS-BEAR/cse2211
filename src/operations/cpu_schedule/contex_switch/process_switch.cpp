#include "../../../utils/timer_util.h"
#include <numeric>
using namespace std;


void switchProcess(){
    unsigned long long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    pid_t pid = fork();
    int pipefd[2];
    char buf = 'a';
    int ret;
    vector<unsigned long> diff;

    for (int i = 0; i < ITERATIONS; ++i){
        if (pid < 0){
            cout << "Fork Fail!"<<endl;
        }
        if (pid == 0){
            //child process
            
            timer_start;
            ret = read(pipefd[0], &buf, 1);
            timer_end;
            exit(0);

        }else{
            ret = write(pipefd[1], &buf, 1);
            
        }
        diff.push_back(getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1));
    }
    cout << "process switch time: " << double(std::accumulate(diff.begin(), diff.end(), 0)) / diff.size()<<endl;

}




int main(){
    setPriority(-20);
    switchProcess();
    return 0;
}