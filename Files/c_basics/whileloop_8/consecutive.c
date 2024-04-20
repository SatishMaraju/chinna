//Find the sum of first n consecutive numbers starting from 1. n will be given as input.


#include<stdio.h>
int main()
{
	int i=1,n,temp=0;
	printf("enter the n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	temp=temp+i;
	i++;
	}
printf("consecutive:%d\n",temp);
}
