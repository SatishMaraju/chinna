/*  Write a program to input a number and count the digits in it.
Eg.
0 - number of digits 1
12 – number of digits 2
155 – number of digits 3      */


#include<stdio.h>
int main()
{
	int a,b,temp=0;
	printf("enter a value:");
	scanf("%d",&a);
	do
	{
	a=a/10;
	temp++;
	} while(a>0);
	
	printf("%d\n",temp);
}
