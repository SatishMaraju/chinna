/*  Declare a two-dimensional array of elements for sales details of a store, for each item, for each salesman. Take the sales values as input and print the array in matrix form.
    Find out and print the following :
    1 ) Total sales by each sales man
    2 ) Total sales for a item
    3 ) Total sales
 */


#include<stdio.h>
int main()
{
	int m,n,i,j,s=0,t=0,u=0;
	printf("enter m and n:");
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}



	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}       

	// 3) Total sales

	for(i=0;i<m;i++ )
	{
		for(j=0;j<n;j++)
		{
			s=s+a[i][j];
		}

	}

	printf("total sales:%d",s);

	printf("\n");
	printf(" Total sales by each sales man\n");

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			t=t+a[i][j];
		}
		printf("i:%d is %d",i,t);
		t=0;
		printf("\n");
	}
	printf("\n");
	printf("Total sales for a item\n");

	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			u=u+a[i][j];
		}
		printf("j:%d is %d",j,u);
		u=0;
		printf("\n");
	}
}
