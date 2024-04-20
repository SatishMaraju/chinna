//check if an year is leap year or not.


#include<stdio.h>
int main()
{
	int a;
	printf("enter the year :");
	scanf("%d",&a);
	a%400==0?printf("leap year"):a%100!=0?a%4==0?printf("leap year"):printf("not leap year"):printf("not leap year");
	return 0;
}
