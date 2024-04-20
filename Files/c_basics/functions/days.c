//Write a function to accept a month and year as input, and return the number of days in that month as output. print the number of days in main.


#include<stdio.h>
int days(int m,int y)
{
	switch(m)
	{
	case 4:
	case 6:
	case 9:
	case 11:return 30;break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:return 31;break;
	case 2:if((y%400==0)||(y%4==0&&y%100!=0))
		return 29;
		else
		return 28;
	default:printf("invalid");
	}}
int main()
{
int m,y,s;
printf("enter month and year:\n");
scanf("%d/%d",&m,&y);
s=days(m,y);
if(s==30)
printf("30 days");
else if(s==31)
printf("31 days");
else if(s==29)
printf("29 days");
else
printf("28 days");
}
