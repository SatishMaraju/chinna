#4. Write script to determine whether given file exist or not, file name is supplied as command line argument, Also check for sufficient number of command line arguments.

#!/bin/bash
ls $1

if [ $? -eq 0 ]
then
echo "file exist"
else
echo "file does not  exist"
fi
