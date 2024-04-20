#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc,char *argv[])
{
	int i,ret,fd;
	struct stat chinna;
	char *buffer,*a;
	
	fd = open(argv[1],O_RDONLY);
	ret = fstat(fd,&chinna);
	if(ret<0)
	perror("message:");
	printf("size of the abc file:%ld\n",chinna.st_size);
	buffer=mmap(NULL,chinna.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	a=buffer;
	for(i=0;i<=chinna.st_size;i++)
	{
		printf("%c",*buffer);
		buffer++;
	}	
	munmap(a,chinna.st_size);	
	return 0;
}
