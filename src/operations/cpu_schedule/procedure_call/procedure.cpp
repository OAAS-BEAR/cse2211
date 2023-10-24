#include <iostream>
#include <stdio.h>
#include "../../../utils/timer_util.h"
using namespace std;
void func0(){
}
void func1(int argument1){
}
void func2(int argument1,int argument2){
}
void func3(int argument1,int argument2,int argument3){
}
void func4(int argument1,int argument2,int argument3,int argument4){
}
void func5(int argument1,int argument2,int argument3,int argument4,int argument5){
}
void func6(int argument1,int argument2,int argument3,int argument4,int argument5,int argument6){
}
void func7(int argument1,int argument2,int argument3,int argument4,int argument5,int argument6,int argument7){
}
int loop=1000;
void test_func0(){      
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func0();
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 0 argument:"<<mean<<" std:"<<standard<<endl;
}
void test_func1(){
    vector<unsigned long>durations;
    int argument1;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func1(argument1);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 1 argument:"<<mean<<" std:"<<standard<<endl;
}
void test_func2(){
    int argument1,argument2;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func2(argument1,argument2);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 2 arguments:"<<mean<<" std:"<<standard<<endl;

}

void test_func3(){

    int argument1,argument2,argument3;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func3(argument1,argument2,argument3);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 3 arguments:"<<mean<<" std:"<<standard<<endl;
}

void test_func7(){
    int argument1,argument2,argument3,argument4,argument5,argument6,argument7;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func7(argument1,argument2,argument3,argument4,argument5,argument6,argument7);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 7 arguments:"<<mean<<" std:"<<standard<<endl;
}
void test_func6(){
    int argument1,argument2,argument3,argument4,argument5,argument6;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func6(argument1,argument2,argument3,argument4,argument5,argument6);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 6 arguments:"<<mean<<" std:"<<standard<<endl;
}
void test_func5(){

    int argument1,argument2,argument3,argument4,argument5;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func5(argument1,argument2,argument3,argument4,argument5);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 5 arguments:"<<mean<<" std:"<<standard<<endl;
}
void test_func4(){
    int argument1,argument2,argument3,argument4;
    vector<unsigned long>durations;
    for(int i=0;i<loop;i++){
        unsigned long start, end;
        start = __rdtsc();
        func4(argument1,argument2,argument3,argument4);
        end = __rdtsc();
        durations.push_back((end - start));
    }
    double mean=MEAN(durations);
    double standard=STD(durations);
    cout<<"The mean cycles needed for calling precedure with 4 arguments:"<<mean<<" std:"<<standard<<endl;
}

int main(){
    setPriority(-20);
    test_func0();
    test_func1();
    test_func2();
    test_func3();
    test_func4();
    test_func5();
    test_func6();
    test_func7();
}
