//Write a function to modify the array such that all negative numbers are converted to positive.

#include<stdio.h>
int main()
{
int n,i;
printf("enetr size");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++)
{
if(arr[i]<0)
printf("%d\n",-arr[i]);
else
printf("%d\n",arr[i]);
}}
