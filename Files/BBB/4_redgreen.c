/*Exp 4: Lab Assignment - Blink LED's

  Write a system program to 
  whenever UP Switch (GPIO0_26) Press blink GREEN LED(GPIO0_9) otherwise 
  always Blink RED LED(GPIO0_10) every 1 sec Delay.

Hint: 
- Create a two threads one is red_led thread and another one is green_led thread.
- red_led thread keep on blinking red led every 1 sec delay without any interruption.
- main thread keep on read UP switch event, whenever UP switch press set global flag (green_led_flag) is TRUE.
- green_led thread keep on checks global flag, whenever global flag is TRUE blink GREEN LED one iteration and immediately global flag set to FALSE (green_led_flag=0).

 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>
pthread_t red,green;
int fd,fd1,fd3,fd4,a,b,l,ret,green_led_flag;
void *red_led(void *arg)
{

	while(1)
	{
		if(green_led_flag==0)
		{
			write(fd,"1",1);
			sleep(1);
			write(fd,"0",1);
			sleep(1);
		}
	}
}
void *green_led(void *arg)
{
	while(1)
	{
		if(green_led_flag==1)
		{	
			write(fd3,"1",1);
			sleep(1);
			green_led_flag=0;
			write(fd3,"0",1);
			sleep(1);
		}
	}
}
int main()
{
	struct input_event v;

	fd=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0){
		perror("open1 fail");}
	write(fd,"10",5);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(fd<0){
		perror("open2 fail");}
	write(fd,"out",5);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd<0){
		perror("open2 fail");}

	fd1=open("/dev/input/event0",O_RDWR);
	if(fd1<0){
		perror("open3 fail");}

	fd3=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0){
		perror("open4 fail");}
	write(fd3,"9",1);
	close(fd3);

	fd3=open("/sys/class/gpio/gpio9/direction",O_WRONLY);
	if(fd<0){
		perror("open5 fail");}
	write(fd3,"out",3);
	close(fd3);
	fd3=open("/sys/class/gpio/gpio9/value",O_WRONLY);
	if(fd3<0){
		perror("open6 fail");}
	ret=pthread_create(&red,NULL,red_led,NULL);
	if(ret<0)
	{
		perror("pthread_create fail");
	}

	ret=pthread_create(&green,NULL,green_led,NULL);
	if(ret<0)
	{
		perror("pthread_create fail");
	}
	while(1)
	{
		l=sizeof(v);
		read(fd1,&v,l);
		if((v.code)==115)
			green_led_flag=1;
	}
	close(fd);
	close(fd1);
	close(fd3);
	fd=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd<0)
		perror("open4 fail");
	write(fd,"10",5);
	close(fd);

	fd3=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd3<0)
		perror("open4 fail");
	write(fd3,"9",5);
	close(fd3);
	return 0;
}	

