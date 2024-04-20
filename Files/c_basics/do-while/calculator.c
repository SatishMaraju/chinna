/*    Modify the Calculator Program to take input and perform the chosen operation. If the user chooses one of the operations, +,-,*,/ and % then show the output and continue for next iteration.
If the user chooses wrong operation, then stop the loop.   */


#include<stdio.h>
int main()
{
char ch;
int a,b;
printf("enter a and b:");
scanf("%d%d",&a,&b);
do
{
printf("enter the charecter:");
scanf(" %c",&ch);
if(ch=='+')
printf("%d %c %d=%d\n",a,ch,b,a+b);
if(ch=='-')
printf("%d %c %d=%d\n",a,ch,b,a-b);
if(ch=='*')
printf("%d %c %d=%d\n",a,ch,b,a*b);
if(ch=='/')
printf("%d %c %d=%d\n",a,ch,b,a/b);
if(ch=='%')
printf("%d %c %d=%d\n",a,ch,b,a%b);
}
while(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%');
}

