//Write a program to find the power of a number by taking power and exponents as inputs.



#include<stdio.h>
int main()
{
	int i=1,n,a;
	unsigned long int temp=1;
	printf("enter power value:");
	scanf("%d",&n);
	printf("enter exponent number:");
	scanf("%d",&a);
	while(i<=n)
	{
	temp=temp*a;
	i++;
	}
	printf("%lu\n",temp);
}
