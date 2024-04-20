


#include<stdio.h>
int main()
{
int n,d,m,y,d1,m1,y1,i=1;
printf("enter n value:");
scanf("%d",&n);
while(i<=n)
{
scanf("%d-%d-%d",&d,&m,&y);
scanf("%d-%d-%d",&d1,&m1,&y1);
if(y==y1)
			
	if(m==m1)
		
		if(d==d1)
		printf("both same");
		else if(y>y1)
		printf("2nd is older %d-%d-%d",d1,m1,y1);
		else
		printf("1st is older %d-%d-%d",d,m,y);
	else if(m>m1)
	printf("2nd is older %d-%d-%d",d1,m1,y1);
	else
	printf("1st is older %d-%d-%d",d,m,y);
	
else if(d>d1)
printf("2nd is older %d-%d-%d",d1,m1,y1);
else
{
printf("1st is older %d-%d-%d",d,m,y);}
i++;
}
}

