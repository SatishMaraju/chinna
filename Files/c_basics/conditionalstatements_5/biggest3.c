//Write a program to find the biggest of three numbers using conditional operator.



#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter a,b and c values:\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("the biggest number is:%d\n",a>b?a>c?a:c:b>c?b:c);
	return 0;
}
