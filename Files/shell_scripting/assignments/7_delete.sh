#7. Write a shell script that deletes all lines containing a specified word in one or more files supplied as arguments to it.


#!/bin/bash

i=1
k=$1
shift     # deleting first aruement if it is not delete then is is taken as a file.
for i in $@
do	
	sed -i /$k/d  $i     #deleting the lines
done
