//Write a program to print all odd numbers and even numbers between two given numbers. print odd numbers in one loop and even in another loop after that.



#include<stdio.h>
int main()
{
	int a,b,a1,b1;
	printf("enter a:");
	scanf("%d",&a);
	printf("enter b:");
	scanf("%d",&b);
	a1=a,b1=b;
	for(a;a<=b;a++)
	{
	if(a%2==0)
	printf("evens are:%d\n",a);
	}

	for(a1;a1<=b1;a1++)
	{
	if(a1%2!=0)
	printf("odds are:%d\n",a1);
	}
	
}
