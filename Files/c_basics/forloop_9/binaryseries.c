/*  Print the beilow patterns wihtout using nested for loop:
    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1     */


#include<stdio.h>
int main()
{
	/*	int i,j=1,temp,a;
		for(i=1;i<=5;i++)
		{
		for(j=1;j<=i;j++)
		{
		if((i+j)%2==0)
		a=1;
		else
		a=0;
		a=a;
		printf("%d",a);
		}
		printf("\n");
		}
		}
	 */	

int i,j,b,a;
printf("enter a:");
scanf("%d",&a);
for(i=1;i<=a;i++)
{ j=1;
	while(j<=i)
	{
		if((i+j)%2!=0)
		{
			b=0;
		}
		else
		{
			b=1;
		}
	
		printf("%d",b);
		j++;}
	printf("\n");}
	}
