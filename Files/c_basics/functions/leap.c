//Write a function to accept a year as input and return 1 if the year is a leap year, otherwise 0.

#include<stdio.h>
int leap(int a)
{
int ret=1;
if((a%4==0&&a%100!=0)||(a%400==0))
return ret;
else
ret=0;
return ret;
}
int main()
{
int a,s;
printf("enter the year:\n");
scanf("%d",&a);
s=leap(a);
if(s==1)
printf("leap");
else
printf("not leap");
}
