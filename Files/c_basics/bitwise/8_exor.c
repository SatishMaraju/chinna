//WAP implements XOR functionality without using XOR(^) operator.


#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	printf("enter a and b:\n");
	scanf("%d%d",&a,&b);
	c=~a;
	d=~b;
	e=((a&d)|(b&c));
	printf("%d",e);
}
