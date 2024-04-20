// Write a program to print the series 1-(1/2!)+(1/3!)-.....(1/n)

#include<stdio.h>
int main()
{
	int i=1,n,sign=1,fact=1;
	float sum=0;
	printf("enter n value");
	scanf("%d",&n);
	while(i<=n)
	{
		fact=fact*i;
		sum=sum+(float)1/fact*sign;
		sign=-sign;
		i++;
	}
	printf("result is:%f\n",sum);
}

