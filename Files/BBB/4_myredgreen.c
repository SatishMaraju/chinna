/* Write a system program to whenever UP Switch (GPIO0_26) Press blink GREEN LED(GPIO0_9) otherwise always Blink RED LED(GPIO0_10) every 1 sec Delay.
Hint:
- Create a two threads one is red_led thread and another one is green_led thread.
- red_led thread keep on blinking red led every 1 sec delay without any interruption.
- main thread keep on read UP switch event, whenever UP switch press set global flag (green_led_flag) is TRUE.
- green_led thread keep on checks global flag, whenever global flag is TRUE blink GREEN LED one iteration and immediately global flag set to FALSE (green_led_flag=0).
 */

#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/types.h>
#include <linux/input.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int green_led_flag,i,a,j,b=10,c,x=1,y=0,d,e,f,g,fd,fd1;

void *red_fun();
void *green_fun();
struct input_event s;
int main()
{
	void *retval;
	pthread_t red,green;
	fd=pthread_create(&red,NULL,red_fun,0);
	fd1=pthread_create(&green,NULL,green_fun,0);
	if(fd<0){perror("mes:");}
	a=open("/sys/class/gpio/export",O_WRONLY);
	if(a<0){perror("mes:");}
	write(a,"10",5);
	a=open("/sys/class/gpio/export",O_WRONLY);
	if(a<0){perror("mes:");}
	write(a,"9",5);
	c=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(c<0){perror("mes:");}
	write(c,"out",5);
	c=open("/sys/class/gpio/gpio9/direction",O_WRONLY);
	if(c<0){perror("mes:");}
	write(c,"out",5);
	while(1)
	{
		j=sizeof(s);
		open("/dev/input/event0/",O_RDWR);
		read(d,&s,j);
		if(s.code==115){
			green_led_flag=1;}
	}
	pthread_join(red,&retval);
	pthread_join(green,&retval);
	g=open("/sys/class/gpio/unexport",O_WRONLY);
	if(g<0){perror("mes:");}
	write(g,"10",5);
	g=open("/sys/class/gpio/unexport",O_WRONLY);
	if(g<0){perror("mes:");}
	write(g,"9",5);
	close(a);
	close(c);
	close(g);
	return 0;
}

void *red_fun()
{
	while(1)
	{	
		e=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		write(e,"1",5);
		sleep(1);
		//close(e);
		f=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		write(f,"0",5);
		sleep(1);
		//close(f);
	}
	close(e);
	close(f);
}
void *green_fun()
{
	while(1)
	{
		if(green_led_flag==1)
		{
			f=open("/sys/class/gpio/gpio10/value",O_WRONLY);
			write(f,"0",5);
			e=open("/sys/class/gpio/gpio9/value",O_WRONLY);
			write(e,"1",5);
			sleep(1);
			write(e,"0",5);
			sleep(1);
			green_led_flag=0;
		}
	}
	close(e);
	close(f);
}
