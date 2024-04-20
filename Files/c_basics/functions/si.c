//Write a function to calculate simple interest. Call it in main function with appropriate inputs and print the total amount the user will get after the tenure (principle + interest).


#include<stdio.h>
float simpleinterest(int p,int n,float r)
{
	float si,y;
	y=n/12.0;
	si=(p*r*y)/100;
	return si;
}
int main()
{
	int p,n;
	float si,r;
	printf("enter the p,n and r\n");
	scanf("%d%d%f",&p,&n,&r);
	si=simpleinterest(p,n,r);
	printf("the total is:%f\n",si+p);
	return 0;
}
