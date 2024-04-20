#1. Write shell script that will add two nos, which are supplied as command line argument, and if this two nos are not given show error and its usage

#!/bin/sh

if [ $# -eq 2 ]
then 
sum=$(($1+$2))
echo "$sum"
else
echo "less/more than 2 arguements"
fi
