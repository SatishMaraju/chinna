/*  Write a program to print the address of a variable , its value ,its size, try different executions and note the address printed. Assign the address of the variable to a pointer variable.Print the size of pointer and its indirected value (apply * operator).    */


#include<stdio.h>
int main()
{
	int x=10;
	int *p=&x;
	printf("x:%d\n",x);
	printf("sizeof x:%ld\n",sizeof(x));
	printf("&x:%p\n",&x);
	printf("p:%p\n",p);
	printf("sizeof p:%ld\n",sizeof(p));
	printf("*p:%p\n",&p);
	printf("p:%p\n",p);
	printf("*p:%d\n",*p);
}
