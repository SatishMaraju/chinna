/* Read a number, and print its multiplication table upto 10 multiples.

eg., input : 5
output: 
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
.
.
5 * 10 = 50  */


#include<stdio.h>
int main()
{
	int i=1,n=10,a;
	printf("enter a value:");
	scanf("%d",&a);
	while(i<=n)
	{
	printf("%d*%d=%d\n",a,i,a*i);
	i++;
}}
