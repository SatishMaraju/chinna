// 9) char * strchr( char s[], char c); // returns address of given character first occurrence in given string.


#include <stdio.h>
#include<string.h>
char* mystrchr(char*,char);
int main()
{
	char str[1000];
	printf("Enter a string: ");
	scanf("%[^\n]s",str);
	char ch;
	printf("Enter a character: ");
	scanf(" %c",&ch);
	printf("Index of %c in %s is: %p\n",ch,str,mystrchr(str,ch));
}
char* mystrchr(char str[], char ch)
{
	for (int i=0;*(str+i);i++)
	{
		if (*(str+i)==ch)
		return str;
		
	}
}
