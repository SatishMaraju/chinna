#8. Write a shell script that displays a list of all the files in the current directory to which the user has read, write and execute permissions.

#!/bin/sh

for i in *
do
 if [ -r $i ]
 then 
  if [ -w $i ]
  then
   if [ -x $i ]
   then
#	k= ls -l $i
   echo "$i"
   fi
  fi
 fi
done
