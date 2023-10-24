cmake_minimum_required(VERSION 3.1)
project(system_evaluation)

### Set Compiler type
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

### Check Compiler Type
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC")
else()
    message(WARNING "You are not using GCC!")
endif()

### Turn off the GCC optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

### Add utils directory
include_directories(utils)

### Add your executables below:
add_executable(measurement_overhead operations/cpu_schedule/measurement/measurement.cpp)
set_target_properties(measurement_overhead PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CPU)

add_executable(task_creation_overhead operations/cpu_schedule/task_creation/task_creation.cpp)
set_target_properties(task_creation_overhead PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CPU)
### Do not modify other parts