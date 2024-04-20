/*Calculation of simple interest.
steps:
1)declare 2 integer variables p and n to represent principle and duration in months respectively.
2)declare a floating point variable r to represent rate of interest.
3)declare a floating point variable si to store simple interest after calculation.
4)declare a floating point variable m to represent time duration in years.
5)print the following indicative message using printf
 "please enter principle,time in months and rate of interest"
5)read the values of p ,n and r using scanf.
6)devide n by 12.0 using / symbol and store the result in m, to convert time duration from months to years.
Hint : m = n / 12.0;
7)calculate simple interest using the below formula and store in si variable.
si = p * m * r / 100;
8) print si value to the user using printf.*/



#include<stdio.h>
int main()
{
	int p;
	int n;
	float r;
	printf("enter p,n,r values:");
	scanf("%d%d%f",&p,&n,&r);
	float m=n/12;
	float si=(p*m*r)/100;
	printf("%f\n",si);
	return 0;
}
	
