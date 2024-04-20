#include<stdio.h>
int main()
{
	int d1,d2,m1,m2,y1,y2;
	printf("enter the 1st person DOB(dd-mm-yyyy):\n");
	scanf("%d-%d-%d",&d1,&m1,&y1);
	printf("enter the 2nd person DOB(dd-mm-yyyy):\n");
	scanf("%d-%d-%d",&d2,&m2,&y2);
	if(y1==y2)
		{
		if(m1==m2)
			{
			if(d1==d2)
			{
			printf("both ages are same");
			}
			else if(d1>d2)
			printf("Person born on %d-%d-%d is elder",d2,m2,y2);
			else
			printf("Person born on %d-%d-%d is  elder",d1,m1,y1);
			}
		else if(m1>m2)
			printf("Person born on %d-%d-%d is elder",d2,m2,y2);
			else
			printf("Person born on %d-%d-%d is elder",d1,m1,y1);
			}
	else
	{
	if(y1>y2)
	printf("Person born on %d-%d-%d is lder",d2,m2,y2);
	else
	printf("Person born on %d-%d-%d is elder",d1,m1,y1);
	}
return 0;
}
	
