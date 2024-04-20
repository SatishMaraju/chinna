//WAP whether a number is a power of 2 or not?


#include<stdio.h>
int main()
{
	int x,z;
	printf("enter value:");
	scanf("%d",&x);
	z=sizeof(x);
	int i,count=0;
	for(i=0;i<z*8;i++)
	{
		if(x&(0x1<<(z*8)-1)){
			printf("1");
			count ++; }
		else;
		x=x<<1;
	}
	printf("%d\n",count);
	if(count==1)
	{
		printf("power of 2");
	}
	else
		printf("not power of 2");
}
