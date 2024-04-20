//Write a program to read 2 numbers and print the biggest of the two numbers.


#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a and b:");
	scanf("%d%d",&a,&b);
	if (a<b)
	{
	printf("biggest number is:%d\n",b);
	}
	else
	{
	printf("the biggest number is:%d\n",b);
	}
	return 0;
}
