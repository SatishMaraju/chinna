#include<stdio.h>
extern int a,b,l;
int operator()
{
char ch;
printf("enter charecter:");
scanf(" %c",&ch);
switch(ch)
{
case '+':l=a+b;break;
case '-':l=a-b;break;
case '*':l=a*b;break;
case '/':l=a/b;break;
case '%':l=a%b;break;
}
}
