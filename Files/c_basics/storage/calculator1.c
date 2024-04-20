/*Rewrite the calculator program so that the main function is in main.c , remaining functions are in another source code file, operations.c.

1) Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function returns the result as return value.
*/


#include<stdio.h>
int a,b;
int add();
int sub();
int mul();
int div();
int mod();
int main()
{
printf("enter a and b:");
scanf("%d%d",&a,&b);
char ch;
printf("enter charecter:");
scanf(" %c",&ch);
switch(ch)
{
case '+':printf("%d",add(a,b));break;
case '-':printf("%d",sub(a,b));break;
case '*':printf("%d",mul(a,b));break;
case '/':printf("%d",div(a,b));break;
case '%':printf("%d",mod(a,b));break;
}}
