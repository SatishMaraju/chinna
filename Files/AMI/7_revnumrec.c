// Print the given number in reverse order using recursion.


#include<stdio.h>
int funrev(int);
int r=0;
int main()
{
	int n;
	printf("enter the number: ");
	scanf("%d",&n);
	printf("%d",funrev(n));
}
int funrev(int n)
{
	int t=0;
	if(n==0)
	return r;
	else
	{
		t=n%10;
		r=r*10+t;
		return funrev(n/10);
	}
}
