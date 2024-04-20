// 8) char * strlwr(char s[]); // returns s base address.



#include <stdio.h>
#include <string.h>
char* strlwr( char str[]);
int main()
{
	char str[1000];
	printf("Enter a string in upper cases: ");
	scanf("%[^\n]s",str);
	printf("%s",strlwr(str));
	printf("\n");
}
char* strlwr(char str[])
{
	int len = strlen(str);
	printf("Entered string in lower cases: ");
	for (int i=0;i<len;i++)
	{
		if (*(str+i)>=97 && *(str+i)<=122);
			//(str+i);
		else
		{
			*(str+i) = *(str+i)+32;
			//(str+i);
		}
	}
	return str;
}
