#!/bin/bash
mkdir /home/ubuntu/local/

for i in {1..30}; do
    fallocate -l 64M  "/home/ubuntu/local/file_${i}.txt"
done