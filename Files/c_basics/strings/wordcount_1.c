/* Take a string as an input, and count the number of words in the string. Take space, comma,exclamation, question mark and fullstop as delimitters for word counting.
*/`

#include<stdio.h>
#include<string.h>
int main()
{
char a[100];
printf("enter string\n");
scanf("%[^\n]s",a);
int i=1,count=0;
while(a[i])
{
if(a[i]=='!' ||a[i]=='?' ||a[i]==','||a[i]=='.'||a[i]==' ')
{
count++;}
i++;
}
printf("%d",count);
}
