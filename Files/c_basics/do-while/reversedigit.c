// Write a program to input a number and find and print the reverse of the number.


#include<stdio.h>
int main()
{
	int a,b,temp;
	printf("enter a value:");
	scanf("%d",&a);
	do
	{
		b=a%10;
		temp=b;
		a=a/10;
		printf("%d\n",temp);
	} while(a>0);
}

