#!/bin/bash

g++ -std=c++0x -I /home/boost_1_54_0/ -fopenmp inOutTest.cpp -o inOutTest.exe
./inOutTest.exe 
