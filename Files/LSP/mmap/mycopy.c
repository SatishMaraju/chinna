#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc,char *argv[])
{
	int i,ret,fd1,fd2;
	struct stat chinna;
	char *a,*b;
	char *t1=NULL,*t2=NULL;
	fd1 = open(argv[1],O_RDONLY);
	if (fd1 < 0)
	perror("open1 Fails:");
	fd2 = open(argv[2],O_RDWR|O_CREAT,0666);
	if (fd2 < 0)
	perror("open2 Fails:");
	ret = fstat(fd1,&chinna);
	if (ret < 0)
	perror("stat Fails:");
	a=mmap(NULL,chinna.st_size,PROT_READ,MAP_PRIVATE,fd1,0);
	b=mmap(NULL,chinna.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
	t1=a;
	t2=b;
	for(i=0;i<=chinna.st_size;i++) 
	{
	*b=*a;
	a++;
	b++;
	}
	munmap(a,chinna.st_size);
	munmap(b,chinna.st_size);
	close(fd1);
	close(fd2);
	return 0;}
