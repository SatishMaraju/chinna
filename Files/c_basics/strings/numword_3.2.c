/*   WAP to display the word expansion of a number
eg., Input : 789
Output : Seven Eight Nine"     */

#include<stdio.h>
#include<string.h>
int main()
{
char a[1000];
int l,i;
printf("enter the string\n");
scanf("%[^\n]s",a);
l=strlen(a);
for(i=0;i<l;i++)
{
switch(a[i])
{
case '0':printf("zero ");break;
case '1':printf("one ");break;
case '2':printf("two ");break;
case '3':printf("three ");break;
case '4':printf("four ");break;
case '5':printf("five ");break;
case '6':printf("six ");break;
case '7':printf("seven ");break;
case '8':printf("eight ");break;
case '9':printf("nine ");break;
default:printf("invalid ");
}
}}
