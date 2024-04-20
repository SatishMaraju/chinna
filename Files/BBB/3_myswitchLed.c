/* Write a system program to read UP (GPIO0_26) and DOWN (GPIO0_27) switches,
        Whenever UP switch press RED LED(GPIO0_10) is ON and
        Whenever DOWN switch press RED LED(GPIO0_10) is OFF.

        DOWN Switch Code is 114 and UP Switch code is 115
*/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/input.h>
int main()
{
	int i,a,b=10,c,x=1,y=0,d,e,f,g;
	struct input_event s;
	a=open("/sys/class/gpio/export",O_WRONLY);
	if(a<0){perror("mes:");}
	write(a,"10",5);
	close(a);
	c=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(c<0){perror("mes:");}
	write(c,"out",5);
	close(c);
	e=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	d=open("/dev/input/event0/",O_RDWR);
	while(1)
	{	
		int u=sizeof(s);
		read(d,&s,u);
		if(s.code==115){
		write(e,"1",5);}
		//sleep(1);
		//close(e);
		if(s.code==114){
		write(e,"0",5);}
		//sleep(1);
		//close(f);
	}
	g=open("/sys/class/gpio/unexport",O_WRONLY);
	if(g<0){perror("mes:");}
	write(g,"10",5);
	close(d);
	close(e);
	close(g);
	return 0;
}
