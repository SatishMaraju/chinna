//Write two source files, main.c and swap.c. The main function initializes a two-element array of ints, and then calls the swap function to swap the pair.


#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the arrays size:");
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);}

	for(j=0;j<n;j++)
	{
		scanf("%d",&b[i]);}

	int temp=0;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		a[i]=b[i];
		b[i]=a[i];
	}

	for(i=0;i<n;i++)
	{
		printf("%d %d",a[i],b[i]);
	}


}
