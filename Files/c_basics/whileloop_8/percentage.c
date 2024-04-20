// read the 6 subject scores of n students, calculate their percentage, and print the topper percentage. Print the average class percentage.


#include<stdio.h>
int main()
{
	int i=1,n,a,b,c,d,e,f,x,perc,temp=0,avg=0,class;
	printf("enter no.of value");i
	scanf("%d",&n);
	while(i<=n)
	{
	//printf("no.of students");
	//scanf("%d",&x);
	printf("enter 6 sub marks:");
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	perc=(a+b+c+d+e+f)/6;
	if(temp<perc)
	{
	temp=perc;
	}
	avg=avg+perc;
	i++;
	}
	printf("percentage:%d\n average :%d\n",temp,(avg=avg/n));
}
