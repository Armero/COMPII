#!/bin/bash

make clean
clear
make aula0805a
make aula0805b

echo ""
echo "./aula0805a 1 7  1 2 0 9 0 4 1" #(OK)
./aula0805a 1 7   1 2 0 9 0 4 1
echo ""

echo ""
echo "./aula0805a 1 7 0 1 2 0 9 0 4 1" #(OK)
./aula0805a 1 7 0 1 2 0 9 0 4 1
echo ""

echo "./aula0805a 1 7 0 a 2 0 9 0 4 1" #(OK)
./aula0805a 1 7 0 a 2 0 9 0 4 1
echo ""

echo ""
echo "./aula0805a 2 5 9 6 7 -5 3 3 6 7" #(OK)
./aula0805a 2 5 9 6 7 -5 3 3 6 7
echo ""

echo ""
echo "./aula0805a 2 5 9 6 7 5 3 3 6 7" #(OK)
./aula0805a 2 5 9 6 7 5 3 3 6 7
echo ""

echo ""
echo "./aula0805b 171209041" #(OK)
./aula0805b 171209041
echo ""

echo ""
echo "./aula0805b 1701209041" #(OK)
./aula0805b 1701209041
echo ""

echo ""
echo "./aula0805b 170a209041" #(OK)
./aula0805b 170a209041
echo ""

echo ""
echo "./aula0805b -2596753367" #(OK)
./aula0805b -2596753367
echo ""

echo ""
echo "./aula0805b 2596753367" #(OK)
./aula0805b 2596753367
echo ""