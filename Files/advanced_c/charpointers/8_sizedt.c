// Define a sizeof macro that will find the size of a given data type as a parameter. use pointers.



#include<stdio.h>
#include<string.h>
#define sizeof(z)  (char*)(&z+1) - (char*)&z
int main()
{
	int *a;
	char *ch;
	float *f;
	long *d;
	double *e;
	long double *l;
	printf("int is: %ld\n",sizeof(a));
	printf("char is: %ld\n",sizeof(ch));
	printf("float is: %ld\n",sizeof(f));
	printf("long is: %ld\n",sizeof(d));
	printf("double is: %ld\n",sizeof(e));
	printf("long double is: %ld\n",sizeof(l));
}

