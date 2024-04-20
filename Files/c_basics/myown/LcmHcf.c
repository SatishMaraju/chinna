//  C program to find LCM of two numbers.

#include<stdio.h>
void main() 
{
	int a,b,max;
	printf("Enter the two numbers : ");
	scanf("%d %d",&a,&b);
	max=(a>b)?a:b;  // maximum number between a and b is stored in max
	while(max%a!=0||max%b!=0) 
	{
		max++;
	}
	printf("LCM is: %d",max);
	printf("\nHCF is: %d\n",(a*b)/max);
}


// Product of two numbers = LCM * HCF

// HCF = Product of two numbers / LCM
