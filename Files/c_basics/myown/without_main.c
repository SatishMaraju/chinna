// WAP to to do some operation without including main function


#include <stdio.h>
extern void _exit(register int);
int _start() {
	printf("Chinna\n");
	_exit(0);
}


// commpilation :: gcc -nostartfiles <file_name>
