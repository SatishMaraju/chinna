/* Write a calculator program with 5 functions below to do the operations of addition, subtraction, multiplication, division for quotient and division for remainder.
1) int add (int a, int b) // to be called when user chooses +
2) int sub (int a,int b) // to be called when user chooses -
3) int mul(int a, int b) // to be called when user chooses *
4) int quotient(int a, int b) // to be called when user chooses /
5) int remainder(int a,int b) // to be called when user choose%    */



#include<stdio.h>
int add (int a, int b)
{
return a+b;}
int sub (int a,int b)
{
return a-b;}
int mul(int a, int b){
return a*b;}
int quotient(int a, int b)
{
return a/b;}
int reminder(int a,int b){
return a%b;}
int main()
{
int a,b;
char ch;
printf("enter a,b and charecter");
scanf("%d %c %d",&a,&ch,&b);
switch(ch)
{
case '+':printf("%d+%d=%d",a,b,add(a,b));break;
case '-':printf("%d-%d=%d",a,b,sub(a,b));break;
case '*':printf("%d*%d=%d",a,b,mul(a,b));break;
case '/':printf("%d/%d=%d",a,b,quotient(a,b));break;
case '%':printf("%d %% %d=%d",a,b,reminder(a,b));break;
default:printf("invalid");
return 0;
}}


