#9. Write a shell script that receives any number of file names as arguments checks if every argument supplied is a file or a directory and reports accordingly. Whenever the argument is a file, the number of lines on it is also reported.
#!/bin/sh
i=1
for i in $@
do
	if [ -f $i ]
	then
		echo "$i is FILE"
		echo -n "no.of lines: "
		wc -l $i
	elif [ -d $i ]
	then
		echo "$i is DIRECTERY"
		#i=$(($i+1))
	fi
done
