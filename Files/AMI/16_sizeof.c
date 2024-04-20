// Find the size of a variable without using size of operator.i


#include<stdio.h>
#define size(z) (char *)(&z+1) - (char *)(&z)
int main()
{
	int a=10;
	char b='a';
	float c=1.2;
	double d=12345.123456789098765;
	long double e=1234567765432.2345678987654323456789876543234567;
	printf("%ld",size(a));
	printf("%ld",size(b));
	printf("%ld",size(c));
	printf("%ld",size(d));
	printf("%ld",size(e));
}
