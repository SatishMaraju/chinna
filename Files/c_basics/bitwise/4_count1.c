//WAP to count the bits set (bit value 1 ) in an integer? Find out and compare different possibilities?


#include<stdio.h>
int main()
{
	int x,z;
	printf("enyter value:");
	scanf("%d",&x);
	z=sizeof(x);
	int i,count=0;
	for(i=0;i<z*8;i++)
	{
		if(x&(0x1<<(z*8)-1))
			count ++; 
		else;
		x=x<<1;
	}
	printf("%d",count);
}
