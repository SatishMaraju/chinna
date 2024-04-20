//Write a program to replace a given character by another character in a string.

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	char l,p;
	int n,i,count=0;
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	printf("enter the charecter\n");
	scanf(" %c",&l);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]==l){
			a[i]='p';
			break;}
	}
	printf("%s",a);
}
