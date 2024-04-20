#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//int a;
void mywait(void);
int main()
{
	mywait();
}
void mywait(void)
{
	char l='0';
	int b,c,d,z;char ch;
//	b=open("abc",O_CREAT);
	z=open("abc",O_RDONLY);
	write(1,&l,1);
	while(1){
	c=read(0,&ch,1);
	if(ch==1)
	{
	break;
	}
	//d=write(1,&ch,1);
}}
