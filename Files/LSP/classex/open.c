#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int ret;
char buff[100];
ret=open("abc",O_RDONLY);
printf("%d",ret);
if(ret<0)
{
perror("message:");
}
read(ret,buff,100);
printf("%s",buff);
}
