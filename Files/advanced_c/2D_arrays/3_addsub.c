// Write a program  for matrix addition and subtraction.


#include<stdio.h>
int main()
{
	int m,n,i,j,s=0,t=0,u=0;
	printf("enter 1st matrix m and n:");
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
	int o,p;
	printf("enter 2nd matrix o and p:");
	scanf("%d%d",&o,&p);
	int b[o][p];
	int c[m][n];
	int d[m][n];
	for(i=0;i<o;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}

	for(i=0;i<o;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	// additiom

	if(m==o&&n==p)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
				printf("%d\t",c[i][j]);
			}
			//printf("%d",a[i][j]);
			printf("\n");
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				d[i][j]=a[i][j]-b[i][j];
				printf("%d\t",d[i][j]);
			}
			//printf("%d",a[i][j]);
			printf("\n");
		}

	}
	else
		printf("not possible");
}


