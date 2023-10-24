cmake_minimum_required(VERSION 3.1)
project(system_evaluation)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

### Check Compiler Version
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC")
else()
    message(WARNING "You are not using GCC!")
endif()

### Turn off the GCC optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")


include_directories(utils)

### main.cpp and example.cpp are both used for examples only, just ignore.
### Add your executables below:
add_executable(${PROJECT_NAME} main.cpp)

add_executable(example operations/cpu_schedule/example/example.cpp)
set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exmaple)

add_executable(measurement_overhead operations/cpu_schedule/measurement/measurement.cpp)
set_target_properties(measurement_overhead PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CPU)
### Do not modify other parts