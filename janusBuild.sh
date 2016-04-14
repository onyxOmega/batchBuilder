#!/bin/bash

module load intel
icpc -std=c++0x -I /projects/fischwil/boost_1_54_0/ -fopenmp main.cpp -o isletSimBatch.exe
./isletSimBatch.exe input/test_input.txt

chmod u+x ./root_shell.sh
chmod o+x ./root_shell.sh

./root_shell.sh