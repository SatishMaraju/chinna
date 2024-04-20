//WAP implements addition functionality without using ADD('+') Operator.



#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter a and b:\n");
	scanf("%d%d",&a,&b);
	b=((~b)-(-1));
	printf("%d",a-b);
}
