/*11) Write a function to replace a given substring by another string of same length in a given string, return the destination string base address.
  char * strreplacestr(char * str[], char *sub1[] , char *sub2[]);
  eg., input main string: Kernel Masters
  input substring: er
  input substring to replace: 12
output: K12nel Mast12s
*/


#include <stdio.h>
#include<string.h>
char* mystrchr(char*,char *, char *,int );
int main()
{
	char str[1000],str1[100],str2[100];
	printf("Enter main string: "); 
	scanf("%[^\n]s",str);
	printf("Enter sub string1: ");
	scanf(" %[^\n]s",str1);
	printf("Enter sub string2: ");
	scanf(" %[^\n]s",str2);
	printf("After replacing \"%s\" with \"%s\" is:",str,str2);
	printf("%s\n",mystrchr(str,str1,str2,strlen(str1)));
}

char* mystrchr(char *str, char *ch, char *r,int l)
{
	int k=0,j=0;
	char *t;
	t=str;
	for (int i=0;*(str+i);i++)
	{	
		if (*(str+i)==*(ch))
		{
			k=0;	
			for(j=0;*(ch+j);j++)
			{
			if (*(str+i+j)!=*(ch+j))
			break;
			k++;
			}
			if(k==l)
			{
				for(int b=0;*(r+b);b++)
				{
				*(str+i+b)=*(r+b);
				}
			}
		}
	}
	return t;

}
