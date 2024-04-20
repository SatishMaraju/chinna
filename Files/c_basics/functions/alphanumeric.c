/* Write a function to determine if a character is alphanumeric or not and print the appropriate output in main function. (return 1 if it is alphanumeric, 0 if it is not alpha numeric).
Hint: int fun_alpha_num(char c).  */

#include<stdio.h>
int alphanumeric(char ch)
{
int ret=1;
if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
return ret;
else ret=0;
return ret;
}
int main()
{
char ch,s;
printf("enter the charecter\n");
scanf(" %c",&ch);
s= alphanumeric(ch);
if(s==1)
printf("alphanumeric");
else
printf("not a alphanumeric");
return 0;
}

