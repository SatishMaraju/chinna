// WAP to implement your own system library.

#include <sys/wait.h>
#include <sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

int main()
{
	int a,status;
	char *str="ls";
	a=fork();
	if(a==0)
	{
	execl("/bin/sh","sh","-c",str,0);
	exit(0);
	}
	else
	{
	wait(&status);
	}
}

