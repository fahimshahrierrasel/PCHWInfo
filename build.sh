#!/bin/bash
qmake PCHWInfo.pro -spec linux-g++
make clean
make

printf "\n\n************ Attention ***************\n"
printf "Please run this program as a sudo user\n"
printf "sudo ./PCHWInfo"
printf "\n****************************************\n"
