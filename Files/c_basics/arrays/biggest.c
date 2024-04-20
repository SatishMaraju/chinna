/*  Declare an array of size 10. Enter 10 elements and save them in the array. Print the array . Find out the biggest and smallest numbers and their  indexes and print.*/

#include<stdio.h>
int main()
{
	int arr[10],i,a=0,b=0,m,n;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);}
	for(i=0;i<10;i++)
	{
		if(arr[i]>a)
		a=arr[i];//big
		m=i;
		}b=a;
	for(i=0;i<10;i++)
		{
		if(arr[i]<b){
		b=arr[i];
		n=i;}
		}
	printf("big:%d\t%d\n",a,m);
	printf("small:%d\t%d\n",b,n);
}
