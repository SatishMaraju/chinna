/*  Read a set of n numbers only in ascending order. While reading the numbers, if the user enters a bigger number than previous number, then count it and continue to the next number. If the number is smaller than previous number, then do not count it, and continue to read the next number.  */



#include<stdio.h>
int main()
{
	int i=1,n,count=0,a,temp=0;
	printf("enter the n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	scanf("%d",&a);
	if(temp<a)
	{

	count++;
	temp=a;
	}
	i++;
	}
printf("%d\n",count);
}
