//WAP to print if  a character is alphanumeric or special character, using macro conditions


#include<stdio.h>
#define SMALL(ch) ch>='a'&&ch<='z'
#define BIG(ch) ch>='A'&&ch<='Z'
#define NUM(ch) ch>='0'&&ch<='9'
#define ALPHANUM(ch) SMALL(ch) || BIG(ch) || NUM(ch)
int main()
{
char ch;
printf("enter  charecter");
scanf(" %c",&ch);
if(ALPHANUM(ch))
printf("alphanumeric");
else
printf("charecter");
}
