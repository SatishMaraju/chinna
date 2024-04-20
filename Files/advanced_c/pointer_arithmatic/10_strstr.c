//10) char * strstr(char str[], char sub[]); //returns the address of the character in the main string from where the substring is matching.

#include <stdio.h>
#include<string.h>
char* mystrchr(char*,char *);
int main()
{
	char str[1000],str1[100];
	printf("Enter main string: "); 
	scanf("%[^\n]s",str);
	printf("Enter sub string: ");
	scanf(" %[^\n]s",str1);
	printf("Address of first character of %s in %s is: %p\n",str1,str,mystrchr(str,str1));
}
char* mystrchr(char str[], char *ch)
{
	int k=0,j=0;
	for (int i=0;*(str+i);i++)
	{		
		if (*(str+i)==*(ch))
		{
			for(j=0;*(ch+j);j++)
			{
			if (*(str+i+j)!=*(ch+j))
			break;
			}
			if(*(ch+j)=='\0')
			return str+i;
		}
	}
}
