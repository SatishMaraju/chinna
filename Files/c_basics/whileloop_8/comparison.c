//  Read n dates from user and print the oldest date of all.



#include<stdio.h>
int main()
{
	int i=1,n,d,d1,m,m1,y,y1;
	printf("enter n value:");
	scanf("%d",&n);
	printf("enter date(dd/mm/yyyy):\n");
	scanf("%d/%d/%d\n",&d,&m,&y);
	while(i<n)
	{
	scanf("%d/%d/%d",&d1,&m1,&y1);
		{
		if(y>y1)
		d=d1,m=m1,y=y1;
		else if(y<y1)
		d=d,m=m,y=y;
		else if(m>m1)
		d=d1,m=m1,y=y1;
		else if(m<m1)
		d=d,m=m,y=y;
		else if(d>d1)
		d=d1,m=m1,y=y1;
		else
		d,m,y;
		}
		i++;
		}
		printf("old date is:%d/%d/%d\n",d,m,y);
}
