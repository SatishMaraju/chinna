/*  Write a program with a function that takes two integer arguments, and prints all prime numbers between those numbers using the prime number function written above.return type should be void.

    PrintAllPrimes - return type is void. Should use IsPrime() function written yesterday.  */

int Isprime(int n)
{
	int i,k=0;
	for(i=2;i<=n/2;i++)
	{
	if(n%i==0)
	k++;
	}
	if(k!=0)
	return 0;
	else
	return 1;
}

#include<stdio.h>

void prime(int a,int b)
{
	int o;
	for(int i=a;i<=b;i++)
	{
	o=Isprime(i);
	if(o==1)
	printf("%d\n",i);
	}
}


int main()
{
	int a,b;
	printf("Enter the range :");
	scanf("%d %d",&a,&b);
	prime(a,b);
	return 0;
}
