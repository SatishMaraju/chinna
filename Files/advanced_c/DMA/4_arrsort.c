//  Create a dynamic array of integers. Take input from user , sort the array and display the output.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,n,t;
printf("enter no.of elements:");
scanf("%d",&n);
int *arr=(int *)malloc(20*sizeof(int));
if(arr==NULL)
{
printf("memory not available");
}

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(arr[i]>arr[j])
{
t=arr[i];
arr[i]=arr[j];
arr[j]=t;
}


}}
for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}
free(arr);
}
