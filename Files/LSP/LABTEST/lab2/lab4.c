//WAP to implement own sizeof() operator.

#include<stdio.h>
#define mysize(x) (char *)(&a+1)-(char *)&a
int main()
{
long int a=10;
printf("%ld",mysize(a));
}
