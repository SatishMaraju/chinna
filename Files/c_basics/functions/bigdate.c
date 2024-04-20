//Write a function that takes 2 dates as inputs, and returns 1 if the first date is old, 2 if the second date is old.

#include<stdio.h>
int bigdate(int d1,int m1,int y1,int d2,int m2,int y2)
{
if(y1==y2)
	if(m1==m2)
		if(d1==d2)
		return 3;
		else if(d1>d2)
		return 2;
		else
		return 1;
	else if(m1>m2)
	return 2;
	else
	return 1;
else if(y1>y2)
return 2;
else
return 1;
}
int main()
{
int d1,m1,y1,d2,m2,y2,s;
printf("enter 1st date:\n");
scanf("%d/%d/%d",&d1,&m1,&y1);
printf("enter 2nd date:\n");
scanf("%d/%d/%d",&d2,&m2,&y2);
s=bigdate(d1,m1,y1,d2,m2,y2);
if(s==1)
printf("1st date is old");
else if(s==2)
printf("2nd date is old");
else
printf("both are equal");
}
