//WAP Swap any two numbers using bitwise operators. How does it work?


#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a and b:\n");
	scanf("%d%d",&a,&b);
	a=a^b;
	b=b^a;
	a=a^b;
	printf("a:%d b:%d",a,b);
}
