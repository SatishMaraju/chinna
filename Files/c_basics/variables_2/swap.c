//write a program swap the values of 2 variables.

#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a and b:");
	scanf("%d%d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("%d\n%d\n",a,b);
	return 0;
}
