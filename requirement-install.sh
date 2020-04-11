#!/bin/bash
if [ "$EUID" -ne 0 ]; then
	printf "******************** Warning *********************\n"
	printf "Please run this as a sudo user"
	printf "\n**************************************************\n"
	exit
fi
printf "******************** Information *********************\n"
printf "It Will Take Some Time to install the requirement please be patient...."
printf "\n**************************************************\n"
apt install lshw dmidecode -y
apt install build-essential -y
apt install qtcreator qt5-default qtdeclarative5-dev -y

