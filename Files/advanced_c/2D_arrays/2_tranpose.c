/*  Write the following program :
    Declare a two dimensional array of elements and find and print its transpose.
    eg., if the matrix is :1 3
    		           4 5
   			   7 8

    its transpose should be :1 4 7
    			     3 5 8
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

      
 printf("\n");
	for(j=0;j<n;j++ )
	{
		for(i=0;i<m;i++)
		{
		printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
