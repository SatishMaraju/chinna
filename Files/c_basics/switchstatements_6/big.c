//C program to find biggest of two numbers using switch statement.



#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the numbers a and b:");
	scanf("%d%d",&a,&b);
	c=a>b;
	switch(c)
	{
		case 0:printf("b is bigger:%d\n",b);
		       break;
		case 1:printf("a is bigger:%d\n",a);
		       break;
		default:("invalid");
	}
return 0;
}
