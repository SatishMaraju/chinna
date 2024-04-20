<<Write a network monitor application server_monitor.sh which show the below information

OS name
Architecture version
Kernel version
Internet status
IP Address
Memory Usage
Disk file systems usage
system uptime
Write

#!/bin/bash

#gets  OS name
	a=$(uname -s)    #gets  OS name
	tput bold
	tput setaf 170
	echo "OS name:$a"
#Gets Architecture
	b=$(uname -m)
	tput setaf 2
	tput bold
	echo "Architecture:$b"

#Gets Kernel Version
	b=$(uname -r)
	tput setaf 3
	tput bold
	echo "Kernel Version:$b"

#internet connection public
	tput setaf 4
	tput bold
	ping -c 1 138.197.197.6 > /dev/null 2> /dev/null
#echo "\$?:$?"
if [ $? -eq 0 ]
then
	echo "Internet is Working"
else
	echo "Internet is not Working"
fi

#private IP Address
	tput setaf 5
	tput bold
	IP=$(hostname -I)
	echo "Private IP Add:$IP"

#public IP Address
	tput setaf 6
	tput bold
	IP=$(hostname -i)
	echo "Public IP Add:$IP"
#memory usage
	tput setaf 94
	tput bold
	ip=$(free)
	echo "Memory Usage:$ip"
#disk system udsage
	tput setaf 84
	tput bold
	z=$(df -H)
	echo "Disk Usage:"
	echo "$z"
#system uptime
tput setaf 33
echo "System Uptime"
echo "`uptime -s`"
