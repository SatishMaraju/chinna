//Declare a two dimensional array of characters, read names from the user and print them back with each individual character format (%c) in a loop.


//6 Declare a two dimensional array of characters, read names from the user and print them back with each individual character format (%c) in a loop.
#include<stdio.h>
int main()
{
	int m,n;
	printf("enter m and n:");
	scanf("%d %d",&m,&n);
	char a[m][n],i,j;
	printf("enter elements of first matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %c",&a[i][j]);
		}
	}
	printf("ELEMENTS OF Matrix 1:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c\t",a[i][j]);  
		}
		printf("\n");

	}
}
