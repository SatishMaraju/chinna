/*)Write a program to read two numbers, and print all prime numbers between the given numbers.
print how many prime numbers are there at the end.  */



#include<stdio.h>
int main()
{
	int i,j,a,b,c,count,temp=0;
	printf("enter a and b:");
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
	count=0;
	for(j=1;j<=i;j++)
	{
	if(i%j==0)
	count++;
	}
	if(count==2)
	printf("%d\n",i);
	temp++;
	}
	printf("no.of prime numbers are:%d\n%d\n",temp,count);
}
