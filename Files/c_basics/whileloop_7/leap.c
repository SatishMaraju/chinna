// Read n number of dates, and print each date belongs to leap year or not.


#include<stdio.h>
int main()
{
	int i=1,n,a;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
		scanf("%d",&a);
		if(((a%4==0)&&(a%100!=0))||(a%400==0))
			printf("leap");
		else
			printf("not leap");
		i++;
	}
}
