// WAP to implement your own cat command.

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
	int a,ret;
	char ch;
	a=open("xy",O_RDONLY);
	if(a<0)
	{
	perror("message:");
	}
	while(1)
	{
		ret=read(a,&ch,1);
		if(ret==0)
		break;
		write(1,&ch,1);
	}
	exit(2);
}
