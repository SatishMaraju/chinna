// Reverse of string without using library functions.


#include<stdio.h>
#include<string.h>
int main()
{
char str[1000],temp;
printf("enter the string: ");
scanf("%[^\n]s",str);
int l=strlen(str);
for(int i=0;i<l/2;i++)
{
temp=str[i];
str[i]=str[l-1-i];
str[l-1-i]=temp;
//l--;
}
printf("%s",str);
}
