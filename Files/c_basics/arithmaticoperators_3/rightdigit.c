//Write a program that reads an integer and displays the right-most digit of the number.
(Eg: User enters, 456, the output should be 6).



#include<stdio.h>
int main()
{
	int a;
	printf("enter the number:");
	scanf("%d",&a);
	printf("the result is:%d\n",a%10);
	return 0;
}
