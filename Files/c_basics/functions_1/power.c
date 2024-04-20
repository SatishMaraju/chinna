//Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n, without using * operator


#include<stdio.h>
int power(int a,int n)
{
	int i,j,temp=a,temp1=a;
	for(i=1;i<n;i++)
	{
		for(j=1;j<a;j++)
		{
			temp=temp+temp1;
		}
		temp1=temp;
	}
	return temp1;
}
int main()
{
	int a,n,s;
	printf("entre a and n:");
	scanf("%d%d",&a,&n);
	s=power(a,n);
	printf("%d",s);
}
