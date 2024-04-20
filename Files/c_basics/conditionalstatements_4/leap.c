//check if a given year is leap year or not.




#include<stdio.h>
int main()
{
	int a;
	printf("enter the year:");
	scanf("%d",&a);
	if(a%400==0)
		printf("Given is a leap year:");
	if(a%100!=0)
	{
		if(a%4==0)
		printf("it is a leap year:");
	}
	else
		printf("Given is not a leap year:");
	return 0;
}
