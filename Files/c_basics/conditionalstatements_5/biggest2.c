//Write a program to find the biggest of two numbers using conditional operator.



#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a and b:\n");
	scanf("%d%d",&a,&b);
	printf("biggest number is:%d\n",a>b?a:b);
	return 0;
}
