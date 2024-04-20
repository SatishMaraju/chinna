/* Write a program to find the factorial of a given number.
N! = n * n-1 * n-2 * …. 2 * 1    */



#include<stdio.h>
int main()
{
	int i=1,n;
	unsigned long fact=1;
	printf("enter n value");
	scanf("%d",&n);
	while(i<=n)
	{
	fact=fact*n;
	n--;
	}
	printf("%lu\n",fact);
}
