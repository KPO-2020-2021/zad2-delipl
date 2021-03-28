#!/bin/bash
mkdir build/
cp latwy.dat build/
cp trudny.dat
cd build
cmake .
make 
./ut