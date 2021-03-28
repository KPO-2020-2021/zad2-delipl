#!/bin/bash
mkdir build/
mkdir lib/
cp latwy.dat build/
cp trudny.dat
cd build
cmake ../
make
cd .. 
./build/ut
echo ""
./build/ComplexQuiz latwy