#include<stdio.h>
int main()
{
	unsigned int a=0x100000;
	char *ch=(char *) &a;
	if(*ch)
	{
		printf("little endian");
	}
	else
		printf("big endian");
}
