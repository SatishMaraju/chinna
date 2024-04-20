/*  Read an integer and print it back using function pointers for printf and scanf.

printf declaration to use : int printf(char * , ...);
scanf declaration to use : int scanf(char *, ...);

Try it again using alias name and array of function pointers.
*/



#include<stdio.h>
#include<string.h>

int main()
{
int (*fp[])(const char *,...)={scanf,printf};
int n;
fp[0]("%d",&n);
fp[1]("%d\n",n);
}
