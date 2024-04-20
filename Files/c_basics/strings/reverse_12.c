/* Void strrev( char str[]);

//reverse the string (without using any extra array)

eg., input : str[] = "Kernel";

output : str[] = "lenreK"   */


#include<stdio.h>
#include<string.h>
void mystrrev(char a[]);
int main()
{
char a[1000];
printf("enter the string\n");
scanf("%[^\n]s",a);
mystrrev(a);
}

void mystrrev(char a[])
{
int i,temp=0;
int l=strlen(a);
for(i=0;i<l;i++)
{
temp=a[i];
a[i]=a[l-1];
a[l-1]=temp;
l--;
}
printf("%s",a);
}
