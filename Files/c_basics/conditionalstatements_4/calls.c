//For one type of mobile service, if cost is 250/- upto 100 calls and 1.25/- for each call made over and above 100 calls. Write a program to read number of calls made and compute and print the bill.




#include<stdio.h>
int main()
{
	int calls,n;
	float bill;
	printf("enter the no.of calls:");
	scanf("%d",&calls);
	if(calls>100)
	{
	n=calls-100;
	bill=250+n*1.25;
	printf("the bills is:%f\n",bill);
	}
	else
	printf("the bill is 250 rupees");
	return 0;
}
