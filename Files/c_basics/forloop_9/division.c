/* Write a program to find the quotient and reminder of two given numbers upon division, without using / and % operators considering negative and positive operands.


Hint: Division is continuous subtraction until the reminder is smaller than the devisor.   */



#include<stdio.h>
int main()
{
	int a,b,c,quo=0,x,y;
	printf("enter big and small numbers:");
	scanf("%d%d",&a,&b);
	x=a,y=b;
	if(a<0 && b<0)
		a=-a,b=-b;
	else if(0>a && b>0)
		a=-a;
	else if(a>0 && 0>b)
		b=-b;
	for(quo=0;a>=b;quo++)
	a=a-b;
	{
	if(x>0 && y>0)
	printf("reminder:%d\nquotient:%d\n",a,quo);
	else if(0>a && b>0)
	printf("reminder:%d\nquotient:%d\n",-a,quo);
	else if(0>x && y>0)
	printf("reminder:%d\nquotient:%d\n",-a,-quo);
	else if(0>y && x<0)
	printf("reminder:%d\nquotient:%d\n",a,-quo);}
}
