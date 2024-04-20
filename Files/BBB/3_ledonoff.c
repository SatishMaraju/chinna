#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main()
{
	int fd,fd1,a,b,l;
	struct input_event v;
	fd=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0)
	perror("open1 fail");
	write(fd,"10",5);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(fd<0)
	perror("open2 fail");
	write(fd,"out",5);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd<0)
	perror("open2 fail");
	fd1=open("/dev/input/event0",O_RDWR);
	if(fd1<0)
	perror("open3 fail");
	while(1)
	{
		l=sizeof(v);
		read(fd1,&v,l);
		if((v.code)==115)
		write(fd,"1",5);
		if((v.code)==114)
	      	write(fd,"0",5);
	}
	close(fd);
	close(fd1);
	fd=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd<0)
	perror("open4 fail");
	write(fd,"10",5);
	close(fd);
	return 0;
}
