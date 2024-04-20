//create variables of all data types and then read and print their values using scanf and printf.




#include<stdio.h>
int main()
{
	signed int a;
	unsigned int b;
	signed short int c;
	unsigned short int d;
	signed long int e;
	unsigned long int f;
	signed char g;
	unsigned char h;
	float i;
	double j;
	long double k;
	scanf("%d%u%hd%hu%ld%lu%c%c%f%lf%Lf",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k);
	printf("a=%d\n b=%u\n c=%hd\n d=%hu\n e=%ld\n f=%lu\n g=%c\n h=%c\n i=%f\n j=%lf\n k=%Lf\n",a,b,c,d,e,f,g,h,i,j,k);
	return 0;
}
	
