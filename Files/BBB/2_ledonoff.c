//Write a system program to Blink RED LED(GPIO0_10) every 1 sec delay.


#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i,a,b=10,c,x=1,y=0,d,e,f,g;
	a=open("/sys/class/gpio/export",O_WRONLY);
	write(a,"10",5);
	c=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	write(c,"out",5);
	for(i=0;i<20;i++)
	{
		e=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		write(e,"1",5);
		sleep(1);
		//close(e);
		f=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		write(f,"0",5);
		sleep(1);
		//close(f);
		i++;
	}
	g=open("/sys/class/gpio/unexport",O_WRONLY);
	write(g,"10",5);
	close(a);
	close(c);
	close(e);
	close(f);
	close(g);
	return 0;
}
