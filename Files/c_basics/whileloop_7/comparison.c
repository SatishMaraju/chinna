// Repeat the date comparison program for n times. Read 2 dates n times, every time print which date is old.


#include<stdio.h>
int main()
{
	int i=1,n,d1,d2,m1,m2,y1,y2;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	printf("enter the date(dd/mm/yyyy):\n");
	scanf("%d/%d/%d",&d1,&m1,&y1);
	printf("enter the 2nd date:\n");
	scanf("%d/%d/%d",&d2,&m2,&y2);
	if(y1==y2)
		{
		if(m1==m2)
			{
			if(d1==d2)
			printf("same date\n");
			else if(d1>d2)
			printf("2nd date is high %d/%d/%d\n",d2,m2,y2);
			else
			printf("1st date is high %d/%d/%d\n",d1,m1,y1);
			}
		else if(m1>m2)
		printf("2nd date is high %d/%d/%d\n",d2,m2,y2);
		else
		printf("1st date is high %d/%d/%d\n",d1,m1,y1);
		}
	else if(y1>y2)
	printf("2nd date is high %d/%d/%d\n",d2,m2,y2);
	else
	printf("1st date is high %d/%d/%d\n",d1,m1,y1);
	i++;
}}
