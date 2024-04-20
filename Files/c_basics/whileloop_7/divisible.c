//Write a program to read n numbers, and print if each number is divisible with 10 or not.


#include<stdio.h>
int main()
{
	int i=1,n,k;
	printf("enter the n value:\n");
	scanf("%d",&n);
	while(i<=n)
	{
	scanf("%d",&k);
	if(k%10==0)
	printf("divisible:%d",k);
	else
	printf("not divisible:%d",k);
	i++;
}}
