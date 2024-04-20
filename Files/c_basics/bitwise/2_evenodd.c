//WAP whether a number is ODD or EVEN using bitwise.


#include<stdio.h>
int main()
{
	int x;
	printf("enter value\n");
	scanf("%d",&x);
	if(x&0x1==1)
		printf("odd");
	else
		printf("even");
}
