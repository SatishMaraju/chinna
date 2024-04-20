#11.Write a shell script to find factorial of a given integer.


#!/bin/sh

read a
export t=1
while [ $a -ne 0 ]
do
t=$(($a*$t))
a=$(($a-1))
done
echo "$t"
