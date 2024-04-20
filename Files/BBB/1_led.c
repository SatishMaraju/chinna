/* Control GPIO pins from sys file system entry @ user space

    1. Enter gpio class in sysfs file system,
    $ cd /sys/class/gpio
    2. Enter root login,
    /sys/class/gpio/$ sudo su
    3. Export pin 10,
    /sys/class/gpio/# echo 10 > export
    4. Enter the gpio10 folder,
    /sys/class/gpio/# cd gpio10
    5. Change pin direction to output,
    /sys/class/gpio/gpio10/# echo out > direction
    6. LED ON,
    /sys/class/gpio/gpio10/# echo 1 > value
    7. LED OFF,
    /sys/class/gpio/gpio10/# echo 0 > value
    8. Unexport pin 10,
    /sys/class/gpio/gpio10/# cd ..
    /sys/class/gpio/# echo 10 > unexport
*/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int a,b=10,c,x=1,y=0,d,e,f,g;
	a=open("/sys/class/gpio/export",O_WRONLY);
	write(a,"10",5);
	c=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	write(c,"out",5);
	e=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	write(e,"1",5);
	sleep(1);
	f=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	write(f,"0",5);
	g=open("/sys/class/gpio/unexport",O_WRONLY);
	write(g,"10",5);
	close(a);
	close(c);
	close(e);
	close(f);
	close(g);
	return 0;
}
