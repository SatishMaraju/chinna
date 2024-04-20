/* 5) Implement your own string reverse function using the above swap function to swap the edges while reversing.
   try calling the string reverse function using
   1) string variable
   2) string constant     */

#include<stdio.h>
#include<string.h>
char *mystrrev(char *str);

int main()
{
	char str[100];
	printf("Enter the string:");
	scanf(" %[^\n]s",str);
	printf("%s",mystrrev(str));

}


char *mystrrev(char *str)   
{
	int l=strlen(str);
	char temp;
	for(int i=0;i<l;i++)
	{
		temp=*(str+i);
		*(str+i)=*(str+(l-1));
		*(str+(l-1))=temp;
		l--;
	}
	return str;

}


