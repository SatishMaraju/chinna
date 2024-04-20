/*  Write down a macro to find out the biggest of two numbers.
    MAX(x,y) should define code to find biggest of x and y. Implement array sorting function using this macro (Bubble sort)          */


#include<stdio.h>
#define BIG(x,y) (x>y)
int main()
{
	int i,j,n,temp=0;
	printf("enter size\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{

		for(j=0;j<n-1;j++)
		{
	
			if(BIG(a[j],a[j+1]))

			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}


	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
