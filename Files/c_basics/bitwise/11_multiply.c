//WAP multiply a number by 9 using bit shift.


#include<stdio.h>
int main()
{
	int x,y;
	printf("enter x:");
	scanf("%d",&x);
	y=(x<<3)+x;
	printf("%d",y);
}
