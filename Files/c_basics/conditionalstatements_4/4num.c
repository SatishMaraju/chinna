//Write a program to read 4 numbers and print the biggest of them




#include<stdio.h>
int main()
{
	int a,b,c,d,larg;
	printf("Enter four Numbers\n");
	scanf("%d %d %d %d",&a,&b,&c,&larg);
	if(a>b)
	{
	if(a>c)
	{
	if(a>d)
	{
	printf("a is larg:");
	}
	else
	{
	printf("d is larg:");
	}
	}
	else
	{
	if(c>d)
	printf("c is larg:");
	else
	printf("d is larg:");
	}
	}
	else
	{
	if(b>c)
	{
	if(b>d)
	{
	printf("b is larg:");
	}
	else
	{
	printf("d is larg:");
	}
	}
	else
	{
	 if(c>d)
	{
	printf("c is larg:");
	}
	else
	{
	printf("d is larg:");
	}
	}
	}
	printf("%d is Largest Number",larg);
	return 0;
}
