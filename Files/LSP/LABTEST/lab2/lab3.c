// WAP to implement Zombie process.

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int n,status;
	pid_t a;
	char *name;
	a=fork();
	if(a==0)
	{
		name= "child";
		n =2;
	}
	else
	{
		name="parent";
		n =5;
		sleep(10);
	}
	for(;n>0;n--)
	{
	printf("%s\n",name);
	}
exit(0);
}
