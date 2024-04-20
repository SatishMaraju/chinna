#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void myexit();
int main()
{
	int a;
	
	myexit();
	
}
void myexit(void)
{
	int h;
	char m='1';
	h=open("abc",O_RDWR);
	while(1){
	read(0,&m,1);
	if(m=='1')
	{
	break;}}
	write(1,&m,1);
}
