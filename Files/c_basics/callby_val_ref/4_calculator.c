//Write a function that can take two integers as input, and gives 5 outputs : addition, subtraction, multiplication, quotient and reminder of those two numbers. Print the outputs in the main function.


#include<stdio.h>
void calc();
int *p3;
int *p4;
int *p5;
int *p6;
int *p7;
int main()
{
	int a,b;
	printf("enter a and b:");
	scanf("%d%d",&a,&b);
	calc(a,b);
	printf("sum:%d\n",*p3);
	printf("sub:%d\n",*p4);
	printf("mul:%d\n",*p5);
	printf("div:%d\n",*p6);
	printf("mod:%d\n",*p7);
}

void calc(int a,int b)
{
	int c,d,e,f,g;
	c=a+b;
	p3=&c;
	d=a-b;
	p4=&d;
	e=a*b;
	p5=&e;
	f=a/b;
	p6=&f;
	g=a%b;
	p7=&g;
}
