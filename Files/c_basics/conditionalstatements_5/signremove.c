//Take an integer as input and print its magnitude (remove sign).



#include<stdio.h>
int main()
{
	int a;
	printf("enter the value of a:");
	scanf("%d",&a);
	printf("the number is:%d\n",a<0?(-1*a):a);
	return 0;
}
