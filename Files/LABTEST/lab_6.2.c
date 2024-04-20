/*  WAP to perform operations like below

arr[]={1,2,3,0,1,0,6,0,8}

output:{1,2,3,1,6,8,0,0,0}
*/


#include<stdio.h>
int main()
{

	int i,j,k,size;
	printf("ENter the size of the array");
	scanf("%d",&size);
	int arr1[size];
	int arr2[size];
	printf("Enter the elements of the array");
	for (i=0;i<size;i++)
	{
		scanf("%d",&arr1[i]);
	}
	j=0;k=size-1;
	for(i=0;i<size;i++)
	{
		if(arr1[i]!=0)
		{
			arr2[j]=arr1[i];
			j++;
		}
		else
		{
			arr2[k]=arr1[i];
			k--;
		}
	}

	printf("The elements of the array");
	for(i=0;i<size;i++)
	{
		printf("%d",arr2[i]);
	}}
