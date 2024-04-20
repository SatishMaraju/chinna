//   4) int  strcmp (char s1[], char s2[]);



#include<stdio.h>
#include<string.h>

int myownstrcmp(char *str1, char *str2);
int main()
{
	char str1[100];
	char str2[100];
	int c=0;
	scanf("%[^\n]s",str1);
	scanf(" %[^\n]s",str2);
	if(strlen(str1)==strlen(str2))
	{
		c=myownstrcmp(str1,str2);
		if(c==0)	
			printf("Both are equal\n");
		else if(c==-1||c==1)
			printf("Both are not equal\n");
	}
	else
	{
		printf("Both Strings are not equal\n");
	}
}


int myownstrcmp(char *str1, char *str2)
{
	int c=0;

	{
		for(int i=0;i<strlen(str1);i++)
		{
			if((*(str1+i)-*(str2+i))==0)
			{
				c=0;
			}
			else if((*(str1+i)-*(str2+i))<=0)
			{
				return c=-1;
			}
			else if((*(str1+i)-*(str2+i))>=0)
			{
				return c=1;
			}
		}

		return c;
	}
}
