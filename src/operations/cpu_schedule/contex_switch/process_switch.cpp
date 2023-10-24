#include "../../../utils/timer_util.h"
#include <numeric>
#include <sys/wait.h>
using namespace std;






void switchProcess(){
    uint64_t start, end, duration;
    char buf = 'a';
    int ret;

    vector<double> diff;

    for (int i = 0; i < 1000; ++i){
        int pipefd_c[2];
        int pipefd_p[2];
        pipe(pipefd_c);
        pipe(pipefd_p);
        pid_t pid = fork();
        if (pid < 0){
            cout << "Fork Fail!"<<endl;
        }
        if (pid == 0){
            //child process  
            for(int j = 0; j < ITERATIONS; ++j){
                ret = read(pipefd_p[0], &buf, 1);
                ret = write(pipefd_c[1], &buf, 1);
            }
            exit(0);

        }else{            
            write(pipefd_p[1], &buf, 1);

            start = __rdtsc();
            for(int j = 0; j < ITERATIONS; ++j){
                ret = write(pipefd_p[1], &buf, 1);
                ret = read(pipefd_c[0], &buf, 1);
            }
            end = __rdtsc();
            //cout<< end << " " <<start <<endl;
            diff.push_back(static_cast<double>(end - start)/ITERATIONS);
        }

    }
    size_t spacing = (diff.size() - 1) / 19;
    for (size_t i = 0; i < 20; ++i) {
        std::cout << diff[i * spacing] << " ";
    }
    cout<<endl;
    cout << "process switch time: " << accumulate(diff.begin(), diff.end(), 0.0) / diff.size()<<endl;
}




int main(){
    setPriority(-20);
    switchProcess();
    return 0;
}