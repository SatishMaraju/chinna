// Write a program to add 2 numbers without using addition or subtraction operators.

#include<stdio.h>
int main()
{
	int x,y,c=0;
	printf("enter the numbers: ");
	scanf("%d %d",&x,&y);
	while(y!=0)
	{
		c=x&y;
		x=x^y;
		y=c<<1;
	}
printf("%d",x);
}
