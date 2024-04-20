//Take an integer as input and print its magnitude (remove sign and print only number).




#include<stdio.h>
int main()
{
	int a;
	printf("enter the number:");
	scanf("%d",&a);
	if(a<0)
	{
	printf("%d\n",(-1*a));
	}
	else
	{
	printf("%d\n",a);
	}
	return 0;
}
