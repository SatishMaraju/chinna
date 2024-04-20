/*  void strcpy ( char d[] . char s[]);
    copies all characters from source string (char s[]) to destination string( char d[]) , upto null character ( including null character).

Implementation:

void strcpy_1( char d[], char s[])
{
int i = 0;
while( s[i] != '\0')
{
d[i] = s[i];
i++;
}
d[i] = '\0';
}         */


#include<stdio.h>
#include<string.h>
void  mystrcpy(char d[],char s[]);
int main()
{
	char s[1000];
 	char d[1000];
	printf("enter source string");
	scanf("%[^\n]s",s);
	mystrcpy(d,s);
}

void mystrcpy(char d[],char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		d[i]=s[i];

	}
	printf("The destination string is: %s",d);
}
