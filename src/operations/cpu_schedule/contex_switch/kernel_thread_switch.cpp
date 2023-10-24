#include "../../../utils/timer_util.h"
#include <numeric>
#include <sys/wait.h>
using namespace std;


char buf = 'a';
int ret;


struct PipeData {
    int pipefd_c[2];
    int pipefd_p[2];
};


void* threadFunction(void* arg){
    setPriority(-20);
    PipeData* data = static_cast<PipeData*>(arg);
    for(int j = 0; j < ITERATIONS; ++j){
        ret = read(data->pipefd_p[0], &buf, 1);
        ret = write(data->pipefd_c[1], &buf, 1);
    }
    return nullptr;
}

void switchThread(){
    uint64_t start, end, duration;

    vector<double> diff;

    for (int i = 0; i < 1000; ++i){
        pthread_t thread;
        PipeData data;
        pipe(data.pipefd_c);
        pipe(data.pipefd_p);

        ret = pthread_create(&thread, nullptr, threadFunction, &data);

        
        if (ret != 0) {
            cout << "Error creating thread: " << ret << endl;
            return;
        }
        write(data.pipefd_p[1], &buf, 1);

        start = __rdtsc();
        for(int j = 0; j < ITERATIONS; ++j){
            ret = write(data.pipefd_p[1], &buf, 1);
            ret = read(data.pipefd_c[0], &buf, 1);
        }
        end = __rdtsc();

        ret = pthread_join(thread, nullptr);
        if (ret != 0) {
            cout << "Error finishing thread: " << ret << endl;
            return;
        }
        diff.push_back(static_cast<double>(end - start)/ITERATIONS);
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
    switchThread();
    return 0;
}