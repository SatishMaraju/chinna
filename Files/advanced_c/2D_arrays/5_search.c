/*  Search for an element in a two dimensional array, and print its position - as row and column numbers. write a search function that will receive the array and return row and column indexes as output.
 */

#include<stdio.h>
int b[5];
int * searchfun(int m, int n,int a[m][n]);
int main()
{
	int m,n,s,i,j;
        int *search;
	printf("enter m and n:");
	scanf("%d %d",&m,&n);
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
        search=searchfun(m,n,a);
	printf("row:%d column:%d\n",search[0],search[1]);
}
			int * searchfun(int m, int n, int a[m][n])
			{
                         int i,j,s;
                         printf("enter element");
                         scanf("%d",&s);
			for(i=0;i<m;i++)
			{
			for(j=0;j<n;j++)
			{
			if(a[i][j]==s)
			{
			b[0]=i;
			b[1]=j;
			return b;
			}}}}
