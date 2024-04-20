/* int strlen( char str[]);
returns the length of the string.

Implementation:
//string length is the count of characters till the first null character is found in a string
int strlen_1(char str[])
{
int i;
for(i=0; str[i] != '\0'; i++); // count all characters till null character is found.
return i;  // return the count.
}  */

#include<stdio.h>
#include<string.h>
int mystrlen(char*);
int main()
{
char a[100];
int count=0,l;
printf("enter the string\n");
scanf("%[^\n]s",a);
printf("%d\n",mystrlen(a));
}


int mystrlen(char a[])
{
int i,count=0;
for(i=0;a[i]!='\0';i++)
{
count++;
}
return count;
}
