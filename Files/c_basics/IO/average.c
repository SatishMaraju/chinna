//calculate average of 4 integer numbers and print the output.



#include<stdio.h>
int main()
{
	float a,b,c,d;
	printf("enter a,b,c and d:");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	float x=(a+b+c+d)/4;
	printf("a=%f\n b=%f\n c=%f\n d=%f\n x=%f\n",a,b,c,d,x);
	return 0;
}
