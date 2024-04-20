//Write a program to find the product of two integers without using * operator.



#include<stdio.h>
int main()
{
	int i=1,n,a;
	unsigned long int temp=0;
	printf("enter 1st value:");
	scanf("%d",&n);
	printf("enter 2nd number:");
	scanf("%d",&a);
	while(i<=n)
	{
	temp=temp+a;
	i++;
	}
	printf("%lu\n",temp);
}
