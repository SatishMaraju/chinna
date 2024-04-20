//Read a set of numbers (number of inputs is input) and print if each given number is smaller or bigger than the previous number. For first number there will not be any output as there is no previous number.


#include<stdio.h>
int main()
{
	int i=1,n,temp=0,a;
	printf("enter the n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	scanf("%d",&a);
	if(i>=2)
	if(temp<a)
	printf("bigger than previous:%d\n",temp=a);
	else
	printf("smaller than previous:%d\n",a);
	i++;
}}
