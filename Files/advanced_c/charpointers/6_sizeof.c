// Define a sizeof macro that will find the size of a given variable as a parameter, using pointers.


#include<stdio.h>
#define mysize(z) (char *)(&z+1)-(char *)(&z)
int main()
{
int a=7;
char ch='s';
float f=1.2;
double d=31.23896249;

printf("int :%ld\n",mysize(a));
printf("char :%ld\n",mysize(ch));
printf("float :%ld\n",mysize(f));
printf("double :%ld\n",mysize(d));
}

