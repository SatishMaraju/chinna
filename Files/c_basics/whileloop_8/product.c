//Write a program to find the product of two integers without using * operator.


#include<stdio.h>
int main()
{
	int i=1,n=0,a,b;
	printf("enter the numbers:\n");
	scanf("%d%d",&a,&b);
	while(i<=b)
	{
	n+=a;
	i++;
	}
	printf("the result is:%d\n",n);
}
