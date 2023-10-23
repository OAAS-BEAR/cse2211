# CSE221_Project

## System Evaluation


## Initialization

**Make sure to run the following command in the build directory except mkdir build** 

CMake Download link: [CMakeDownload](https://cmake.org/download/)  (Any version above 3.1 should be enough) ***Remember to put CMake into your PATH when installing***

Step1: Create make file

Cmake version: 3.1 or above  
```
mkdir build
cd build
cmake -S ../src/ 
```

Step2: Compile the file

```make```

## How to add your own executable

Step 1: Suppose you have a main file located at src/operations/cpu_schedule/example/example.cpp.
First you need to add the executable at the CMakeLists.txt in src folder:

```
add_executable(<executable_name>,<address>)
set_target_properties(<executable_name>,PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/<Your expected output address>)

e.g.:
// This will place the executable example at build/example/
add_executable(MyExample,operations/cpu_schedule/example/example.cpp)
set_target_properties(example, PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exmaple)
```

Step 2: You should make sure there's a build directory

```
mkdir build
cd build
cmake -S ../src/
make
```
After this step your new executable should be all set. ***Remember to run the cmake command at the build directory!***