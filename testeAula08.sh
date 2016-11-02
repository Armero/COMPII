#!/bin/bash

make clean
clear
make aula0802a
make aula0802b

echo ""
echo "./aula0802a 1 7  1 2 0 9 0 4 1" #(OK)
./aula0802a 1 7   1 2 0 9 0 4 1
echo ""

echo ""
echo "./aula0802a 1 7 0 1 2 0 9 0 4 1" #(OK)
./aula0802a 1 7 0 1 2 0 9 0 4 1
echo ""

echo "./aula0802a 1 7 0 a 2 0 9 0 4 1" #(OK)
./aula0802a 1 7 0 a 2 0 9 0 4 1
echo ""

echo ""
echo "./aula0802a 2 5 9 6 7 -5 3 3 6 7" #(OK)
./aula0802a 2 5 9 6 7 -5 3 3 6 7
echo ""

echo ""
echo "./aula0802a 2 5 9 6 7 5 3 3 6 7" #(OK)
./aula0802a 2 5 9 6 7 5 3 3 6 7
echo ""

echo ""
echo "./aula0802b 171209041" #(OK)
./aula0802b 171209041
echo ""

echo ""
echo "./aula0802b 1701209041" #(OK)
./aula0802b 1701209041
echo ""

echo ""
echo "./aula0802b 170a209041" #(OK)
./aula0802b 170a209041
echo ""

echo ""
echo "./aula0802b -2596753367" #(OK)
./aula0802b -2596753367
echo ""

echo ""
echo "./aula0802b 2596753367" #(OK)
./aula0802b 2596753367
echo ""