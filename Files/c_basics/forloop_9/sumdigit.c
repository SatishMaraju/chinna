/*  Write a program to input a number and print the sum of the digits of the number.
Eg., 
0 - sum of the digits 0
12 - sum of the digits 3
155 - sum of the digits 11     */



#include<stdio.h>
int main()
{
	int a,b,temp=0,n;
	printf("enter the number:");
	scanf("%d",&a);
	for(a;0<a; )
	{
	n=a%10;
	temp=temp+n;
	a=a/10;
	}
	printf("%d",temp);
}
