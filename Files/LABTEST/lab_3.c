//WAP to check whether the given date is valid or invalid.


#include<stdio.h>
int main()
{
int d,m,y,t;
printf("enter the date(dd/mm/yyyy):");
scanf("%d/%d/%d",&d,&m,&y);
if(y>=1900&&y<=2200)
	{
	if(m>=1&&m<=12)
		{
		if((d>=1&&d<=31)&&((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)))
		t=1;
		else if((d>=1&&d<=30)&&((m==4)||(m==6)||(m==9)||(m==11)))
		t=1;
		else if((d>=1&&d<=28)&&(m==2)||(y=29)&&(y%400==0&&y%100!=0&&y%4==0))
		t=1;
		else
		t=0;}
	}
else
printf("invalid");
switch(t)
{
case 1:printf("valid");
	break;
case 0:printf("invalid");
	break;
default:printf("invalid");
}
}
