/*  void strlwr( char str[]);
// convert all upper case alphabets to lower case in the given string.   */

#include<stdio.h>
#include<string.h>
void mystrlwr();
int main()
{
	char a[10];
	int s;
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	mystrlwr(a);
}
void mystrlwr(char a[])
{
	int i;
	int l;
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if((a[i]>=65)&&(a[i]<=90))
		a[i]=a[i]+32;
	}
printf("%s",a);
}

