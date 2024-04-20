/*  Declare different pointers with different data types. Print the sizes of the pointer variables using sizeof operator. Why do u think all of them are giving same size irrespective of the data type ?      */


#include<stdio.h>
int main()
{
	int *p1;
	char *p2;
	float *p3;
	printf("%ld\t",sizeof(p1));
	printf("%ld\t",sizeof(p2));
	printf("%ld\n",sizeof(p3));
}
