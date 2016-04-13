#!/bin/bash
module load intel
icpc -std=c++0x -I /projects/fischwil/boost_1_54_0/ -fopenmp inOutTest.cpp -o inouttest.exe
./inouttest.exe