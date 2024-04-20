#include<stdio.h>
int endian()
{
	int z,a=10;
	char *p=(char *)&a;
	return (*p==1);
}
int main()
{
if(endian())
printf("little");
else
printf("big");
}
