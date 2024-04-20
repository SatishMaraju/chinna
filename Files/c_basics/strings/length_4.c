/*  Write a program to find the length of a string. Length is the number of characters in a string (null character is not counted).
eg., char name[10] = ""abc""; //size of name is 10 bytes
            // length of name is 3"    */

#include<stdio.h>
#include<string.h>
int main()
{
int l;
char a[1000];
printf("enter the string\n");
scanf("%[^\n]s",a);
l=strlen(a);
printf("%d",l);
}
