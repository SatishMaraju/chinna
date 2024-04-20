int DateCompare(int d1,int m1,int y1, int d2,int m2,int y2)
{
	if(y1<y2||(y1==y2&&m1<m2)||(y1==y2&&m1==m2&&d1<d2))
		return 1;
	else 
		return 0;
}
int IsLeapYear(int);
int IsValidDate(int d,int m,int y)
{
	int r;
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(d>=1 && d<=31)
				return 1;
			else
				return 0;

		case 4:
		case 6:
		case 9:
		case 11:
			if(d>=1 && d<=30)
				return 1;
			else
				return 0;
		case 2:
			r=IsLeapYear(y);
			if(r==1)
			{
				if(d>=1 && d<=29)
					return 1;
				else
					return 0;
			}
			else if(r==0)
			{
				if(d>=1 && d<=28)
					return 1;
				else 
					return 0;
			}
		default:
			return 0;
	}
}

int IsLeapYear(int y)
{
	if((y%4==0 && y%100!=0) || y%400==0)
		return 1;
	else 
		return 0;
}
#include<stdio.h>
#include"dates.h"
int main()
{
	int d1=0,m1=0,y1=0,d2,m2,y2,n,c;
	printf("Enter the no.of Candidates:");
	scanf("%d",&n);
	printf("Enter the Date of Birth of Candidate #1:");
	scanf("%d-%d-%d",&d1,&m1,&y1);
loop:if((IsValidDate(d2,m2,y2))!=1)
     {
	     printf("Date is invalid, Please enter valid date:");
	     scanf("%d-%d-%d",&d2,&m2,&y2);
	     goto loop;
     }
     else
     {
	     for(int i=2;i<=n;)
	     {
		     printf("Enter the Date of Birth of Candidate #%d:",i);
		     scanf("%d-%d-%d",&d2,&m2,&y2);
l1:if((IsValidDate(d2,m2,y2))==1)
   {
	   c=DateCompare(d1,m1,y1,d2,m2,y2);
	   if(c==0)
	   {
		   d1=d2,m1=m2,y1=y2;
		   printf("%d-%d-%d",d1,m1,y1);
	   }	   
	   else
		   d1=d1,m1=m1,y1=y1;


	   i++;
   }
   else
   {
	   printf("Date is invalid, Please enter valid date:");
	   scanf("%d-%d-%d",&d2,&m2,&y2);
	   goto l1;
   }
	     }
     }
     PrintDateinFormat(d1,m1,y1);
     return 0;
}
#include<stdio.h>

void PrintSubscript(int);
void PrintMontName(int);
void PrintDateinFormat(int d,int m,int y)
{
	printf("The Candidate born on %d",d);
	PrintSubscript(d);
	PrintMontName(m);
	printf("-%d is Elder of all\n",y);
}



void PrintSubscript(int d)
{
	switch(d)
	{
		case 1:
		case 21:
		case 31:
			printf("st ");
			break;

		case 2:
		case 22:
			printf("nd ");
			break;
		case 3:
		case 23:
			printf("nd ");
			break;
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			printf("th ");
			break;
	}
}




void PrintMontName(int m)
{
	switch(m)
	{
		case 1:
			printf("January");break;
		case 2:
			printf("Febrauary");break;
		case 3:
			printf("March");break;
		case 4:
			printf("April");break;
		case 5:
			printf("May");break;
		case 6:
			printf("June");break;
		case 7:
			printf("July");break;
		case 8:
			printf("August");break;
		case 9:
			printf("September");break;
		case 10:
			printf("October");break;
		case 11:
			printf("November");break;
		case 12:
			printf("December");break;
	}
}
