//  3) char * strcpy( char d[] , char s[]);  // returns destination base address.



#include<stdio.h>
#include<string.h>
char *myownstrcpy(char *str,char *str1);
int main()
{
	char str[100];
	char str1[100];
	printf("Enter str:");
	scanf("%[^\n]s",str);
	printf("destination:%s",myownstrcpy( str,str1));
	return 0;
}






char * myownstrcpy(char *str,char *str1)
{
	int i=0;
	while(*str1!='\0')
	{
		*(str+i)=(*(str1+i));
		i++;
	}
	*(str1+i)='\0';
	return str;

}
