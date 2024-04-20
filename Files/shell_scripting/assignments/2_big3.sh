#2. Write Script to find out biggest number from given three nos. Nos are supplied as command line arguments. Print error if sufficient arguments are not supplied.

#!/bin/sh
if [ $# -eq 3 ]
then
if [ $1 -le $2 ]
then
	if [ $2 -le $3 ]
	then
	echo "big:$3"
	else
	echo "big:$2"
	fi
else
echo "big:$1"
fi
else
echo "not"
fi
