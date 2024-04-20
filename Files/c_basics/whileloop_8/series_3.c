/*  Find the value of the below series upto n terms:
 9 + 99 + 999 + 9999 .....upto n terms      */


#include<stdio.h>
int main()
{
	int i=1,n,temp=0,sum=0;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	temp=temp*10+9;
	sum=sum+temp;
	i++;

	}
printf("result:%d",sum);
}
