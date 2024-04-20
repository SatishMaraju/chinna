//WAP implements subtraction functionality without using SUB('-') Operator.    



#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a and b:\n");
	scanf("%d %d",&a,&b);
	b=~b+1;
	printf("%d",a+b);
	return 0;
}
