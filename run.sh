#!/bin/bash
mkdir build/
mkdir lib/
cd build
cmake ../
make
cd .. 
./build/ut
echo ""
./build/ComplexQuiz latwy