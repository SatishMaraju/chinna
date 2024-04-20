/*  Find the value of the below series upto n terms:
1 - 1/2 + 1/3 - 1/4 .... 1/n   */


#include<stdio.h>
int main()
{
	int i=1,n,a;
	float sum=0;
	printf("enter n value");
	scanf("%d",&n);
	while(i<=n)
	{
	
	if(i%2==0)
	sum-=(float)1/i;
	else
	sum+=(float)1/i;
	i++;
	}
	printf("result is:%f\n",sum);
}
