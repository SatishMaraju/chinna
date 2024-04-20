//Write a calculator program that takes two integer numbers from user, and one of the operands +,-,* and / as a character and prints the appropriate result using if else.



#include<stdio.h>
int main()
{
	int a,b;
	char i='+',j='-',k='*',l='/';
	char ch;
	printf("enter a,c,b:");
	scanf("%d %c %d",&a,&ch,&b);
	if(ch==i)
	{
	printf("%d %c %d\n%d\n",a,i,b,a+b);
	}
	else if(ch==j)
	{
	printf("%d %c %d\n%d\n",a,j,b,a-b);
	}
	else if(ch==k)
	{
	printf("%d %c %d\n%d\n",a,k,b,a*b);
	}
	else
	printf("%d %c %d\n%d\n",a,l,b,a/b);
	return 0;
}
