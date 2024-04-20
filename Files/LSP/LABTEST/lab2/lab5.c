// WAP to check whether the architecture is a little endian or big endian.

#include<stdio.h>
int main()
{
	unsigned int i=0x100000;
	char *c=(char *)&i;
	if(*c==0x00)
	{
		printf("little endian");
	}
	else
		printf("big endian");
}
