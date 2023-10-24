#include <iostream>
#include <stdio.h>
#include "timer_util.h"

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
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    timer_start;
    for(int i=0;i<loop;i++){
        func0();
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 0 argument:%lu\n",duration);
}
void test_func1(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func1(argument1);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 1 argument:%lu\n",duration);
}
void test_func2(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func2(argument1,argument2);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 2 arguments:%lu\n",duration);
}

void test_func3(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2,argument3=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func3(argument1,argument2,argument3);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 3 arguments:%lu\n",duration);
}

void test_func7(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2,argument3,argument4,argument5,argument6,argument7=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func7(argument1,argument2,argument3,argument4,argument5,argument6,argument7);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 7 arguments:%lu\n",duration);
}
void test_func6(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2,argument3,argument4,argument5,argument6=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func6(argument1,argument2,argument3,argument4,argument5,argument6);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 6 arguments:%lu\n",duration);
}
void test_func5(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2,argument3,argument4,argument5=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func5(argument1,argument2,argument3,argument4,argument5);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 5 arguments:%lu\n",duration);
}
void test_func4(){
    unsigned long cycles_high0, cycles_low0, cycles_high1, cycles_low1;
    int argument1,argument2,argument3,argument4=0;
    timer_start;
    for(int i=0;i<loop;i++){
        func4(argument1,argument2,argument3,argument4);
    }
    timer_end;
    unsigned long duration=getTimeDiff(cycles_high0, cycles_low0, cycles_high1, cycles_low1);
    printf("The cycle needed for calling precedure with 4 arguments:%lu\n",duration);
}

int main(){
    test_func0();
  //  test_func1();
  //  test_func2();
  //  test_func3();
  //  test_func4();
   // test_func5();
   // test_func6();
    //test_func7();
}
