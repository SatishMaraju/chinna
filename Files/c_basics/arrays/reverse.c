//Write a program to print an array in reverse order.

#include<stdio.h>
int main()
{
int n,i;
printf("enter size:");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++){
scanf("%d",&arr[i]);}
for(i=n-1;i>=0;i--)
{
printf("%d\t",arr[i]);
}}
