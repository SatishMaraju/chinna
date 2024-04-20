// Wap to calculate the size of a integer variable in a system without using size of operator.


#include<stdio.h>
#define mysizeof(z) (char *)(&z+1)-(char *)&z
int main()
{
int a=10;
printf("%ld",mysizeof(a));
}
