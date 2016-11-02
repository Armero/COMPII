#!/bin/bash

make clean
clear
make aula0806a
make aula0806b


echo ""
echo "./aula0806a 1 7 0 1 2 0 9 0 4 1 1" #(OK)
./aula0806a 1 7 0 1 2 0 9 0 4 1 1
echo ""

echo ""
echo "./aula0806a 1 7 0 1 2 0 9 0 4 1 2" #(OK)
./aula0806a 1 7 0 1 2 0 9 0 4 1 2
echo ""

echo ""
echo "./aula0806a 2 5 9 6 7 5 3 3 6 7 3" #(OK)
./aula0806a 2 5 9 6 7 5 3 3 6 7 3
echo ""

echo ""
echo "./aula0806b 1701209041" #(OK)
./aula0806b 17012090411
echo ""

echo ""
echo "./aula0806b 1701209042" #(OK)
./aula0806b 17012090412
echo ""

echo ""
echo "./aula0806b 25967533673" #(OK)
./aula0806b 25967533673
echo ""