/* Write a program to convert a string into upper case and print.
   eg., input : Hello
output : HELLO"   */

#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	char l;
	int i;
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	l=strlen(a);
for(i=0;i<l;i++)
{
if(a[i]>=97&&a[i]<=122)
{
a[i]=a[i]-32;
}}
printf("%s",a);
}
