/*  Implement the calculator program using Command line arguments

eg., input:  >./calc   56 + 671
output : 727

note: when giving * in commandline, always give "*"
*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
int a,b;
printf("no.of cmd:%d\t",argc);
printf("cmd:%s\t",argv[0]);
printf("%s\t",argv[1]);
printf("%s\t",argv[2]);
printf("%s\t",argv[3]);
a=atoi(argv[1]);
b=atoi(argv[3]);

switch(*argv[2])
{
case '+':printf("=%d\n",a+b);break;
case '-':printf("=%d\n",a-b);break;
case '*':printf("=%d\n",a*b);break;
case '/':printf("=%d\n",a/b);break;
case '%':printf("=%d\n",a%b);break;
}
}
