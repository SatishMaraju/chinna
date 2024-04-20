// WAP to check if a given number is power of 2 or not.


#include<stdio.h>
int main()
{
	int n,c=0;
	printf("enter the number: ");
	scanf(" %d",&n);
	while(n!=0)
	{
		if(n&0x1)
		c++;
		n=n>>1;
	}
	if(c==1)
		printf("power");
	else
		printf("not power");
}
