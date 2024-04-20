/*    int strchr( char str[], char ch)
search the character ch ,in string str , whenever the first matching occurs, return the matching index.    */



#include<stdio.h>
#include<string.h>
int mystrchr(char str[],char ch);
int main()
{
	char str[1000];
	char ch;
	int n;
	printf("enter the string\n");
	scanf("%[^\n]s",str);
	printf("enter the charecter\n");
	scanf(" %c",&ch);
	printf("%d",mystrchr(str,ch));
	}


int mystrchr(char str[],char ch)
{
int i;
	int l=strlen(str);
	for(i=0;i<l;i++)
	{
		if(str[i]==ch){
		return i;
		break;}
	}
}
