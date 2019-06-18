# Message Passing Examples

## Requirements

Software | URL
------------ | -------------
Notepad++ | https://notepad-plus-plus.org/
Sublime Text | https://www.sublimetext.com/
VirtualBox | https://www.virtualbox.org/wiki/Downloads

## Example List

* sequency.c 	- 	Basic summation from 1 to N 
* Test1.c 		- 	Basic Hello World MPI
* Test2.c 		- 	Environment configuration and rank handle
* Test3.c 		- 	Creating paralell process with arguments
* Test4.c 		- 	Basic paralell summation with Send and Recive synchronization 

## Links

* Virtual Machine Link: https://drive.google.com/open?id=1gOtr74S5qUgpNt3upJtdFUHT_L9hAWpO
* username: campus
* password: campus

## To install Open-MPI in Ubuntu18.04

Just hit the following commands to download the packages in a fresh update Ubuntu Machine

```
sudo apt-get -y install net-tools ssh
sudo systemtcl enable ssh
sudo systemtcl start ssh
sudo apt-get -y install openmpi-bin openmpi-common libopenmpi-dev
mkdir mpi
```