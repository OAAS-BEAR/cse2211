cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(system_evaluation)
include_directories(utils)

### main.cpp and example.cpp are both used for examples only, just ignore.
### Add your executables below:
add_executable(${PROJECT_NAME} main.cpp)

add_executable(procedure operations/cpu_schedule/procedure_call/procedure.cpp)
set_target_properties(procedure PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/procedure)
### Do not modify other parts