#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int b,c,a,ret1;
	char buff[1024],ch;
	a=open(argv[1],O_RDONLY);
	b=open(argv[2],O_CREAT,0666);
	c=open(argv[2],O_WRONLY);
	open(argv[2],O_TRUNC);
	if(a<0)
	{
	perror("message");
	}
	while(1)
	{
	ret1=read(a,buff,sizeof(buff));
	if(ret1==0)
	break;
	write(c,buff,sizeof(buff));
	}
close(a);
close(b);
close(c);}
