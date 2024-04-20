//write a program to print the no.of 2000 notes,500 notes,200 notes,100 notes and 50 notes drawn by the ATM holder in the denominations of 50.



#include<stdio.h>
int main()
{
	int n;
	printf("enter amount of withdraw in denominations of 50:");
	scanf("%d",&n);
	if((n/2000)||(n%2000/500)||(n%2000%500/200)||(n%2000%500%200/100)||(n%2000%500%200%100/50))
	{
	printf("no.of 2000 notes:%d\n",n/2000);
	printf("no.of 500 notes:%d\n",n%2000/500);
	printf("no.of 200 notes:%d\n",n%2000%500/200);
	printf("no.of 100 notes:%d\n",n%2000%500%200/100);
	printf("no.of 50 notes:%d\n",n%2000%500%200%100/50);
	}
	else
	printf("invalid");
return 0;
}

	
