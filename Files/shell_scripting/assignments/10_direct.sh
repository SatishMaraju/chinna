#10.Write a shell script to list all of the directory files in a directory.



#!/bin/sh
for i in *
do
	if [ -d $i ]
	then
		echo "$i"
	fi
done
