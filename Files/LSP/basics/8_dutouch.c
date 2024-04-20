//8.Write a system programming your own version of du & touch command?

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i=0,z=4096,j=1,bytes=0,a=0;
	char ch;
	for(i=1;i<argc;i++)
	{
		a=0;
		int fd,ret;
		fd=open(argv[i],O_RDONLY);
		if(fd<0)
		{
		perror("open fail : ");
		exit(2);
		}
		while(1)
		{
		ret=read(fd,&ch,1);
		if(ret==0)
		break;
		bytes++;	
		}
		while(bytes>0)
		{
		bytes = bytes-z;
		a = a+4;	
		}
		printf("%d	%s\n",a,argv[i]);
		close(fd);
	}
return 0;
}
