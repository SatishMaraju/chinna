#include<stdio.h>
	#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
       #include <sys/wait.h>

int main()
{
	char *str;
	int a,n=0,status;
	a=fork();
	if(a==0)
	{
		n=3;
		str="child";
	}
	else
	{
		n=5;
		str="parent";
		sleep(20);
	}
	for( ;n>0;n--)
	{
		printf("%s\n",str);
	}
}
