# 3. Write script to print given number in reverse order, for eg. If no is 123 it must print as 321

#!/bin/sh
read n
t=0
while [ $n -gt 0 ]
do
	t=$(($t * 10))
	k=$(($n % 10))
	t=$(($t + $k))
	n=$(($n / 10))
done
	echo "reverse is $t"
