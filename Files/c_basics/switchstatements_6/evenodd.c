//C program to check whether a number is odd or even using switch statement.



#include<stdio.h>
int main()
{
	int a,n;
	printf("enter the number:");
	scanf("%d",&a);
	n=(a%2);
	switch(n)
	{
	case 0:printf("even");
	break;
	case 1:printf("odd");
	break;
	default:printf("invalid");
}}
