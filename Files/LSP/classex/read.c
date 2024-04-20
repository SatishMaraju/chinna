#include<unistd.h>
#include<stdio.h>
int main()
{
char buff[89];
int a=read(0,buff,40);
if(a==0)
printf("end of file\n");
else if(a==8)
printf("10 bytes data:%s",buff);
}
