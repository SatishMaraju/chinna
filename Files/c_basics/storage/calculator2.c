/*Rewrite the calculator program so that the main function is in main.c , remaining functions are in another source code file, operations.c.

2)Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function return value should be stored in another global variable in the operations file and be used to print in main.   */


#include<stdio.h>
int a,b,l;
int operator();
int main()
{
printf("enter a and b:");
scanf("%d%d",&a,&b);
l=operator();
printf("%d",l);
}
