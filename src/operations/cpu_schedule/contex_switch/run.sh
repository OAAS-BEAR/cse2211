#!/bin/bash

# Compile the C++ file
g++ process_switch.cpp -pthread -o process_switch
# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. running ./process_switch"
    sudo ./process_switch
    rm -f process_switch
else
    echo "Compilation failed."
fi


g++ kernel_thread_switch.cpp -pthread -o kernel_thread_switch

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running ./kernel_thread_switch"
    sudo ./kernel_thread_switch
    rm -f kernel_thread_switch
else
    echo "Compilation failed."
fi

