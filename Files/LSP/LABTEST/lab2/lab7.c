// WAP to get the corresponding device name.

#include <sys/ioctl.h>
#include<stdio.h>
int main()
{
ioctl("dev/input/event0",SIOCGIFNAME,NULL);
}
