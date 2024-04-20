/*Find the value of the below series upto n terms:
1 + 1/2 + 1/3 + 1/4 .... 1/n
1 - 1/2 + 1/3 - 1/4 .... 1/n
1 - 1/2! + 1/3! - 1/4! + 1/5! ..... 1/n
 9 + 99 + 999 + 9999 .....upto n terms   i*/


#include<stdio.h>
int main()
{
	float i=1,n;
	float temp=0;
	printf("enter the n value:");
	scanf("%f",&n);
	while(i<=n)
	{
	temp=temp+(1/i);
	i++;
	}
printf("series value:%f\n",temp);
}
