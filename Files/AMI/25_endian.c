// Check whether little endian or big endian.


#include<stdio.h>
int main()
{
	int z=0x12345678;
	char *p=(char *)&z;
	if(*p==0x78)
		printf("little");
	else
		printf("big");
}
