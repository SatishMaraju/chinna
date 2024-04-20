//  2)  char * strrev( char s[]); // returns string base address.


#include<stdio.h>
#include<string.h>
char *mystrrev(char *str);

int main()
{
	char str[100];
	printf("Enter the string:");
	scanf(" %[^\n]s",str);
	//mystrrev(str);
	printf("%s",mystrrev(str));

}


char *mystrrev(char *str)			//or u can use this also char * mystrrev(char str[])
{
	int l=strlen(str);
	char temp;
	//		printf("%d",l);	
	for(int i=0;i<l;i++)
	{
		temp=*(str+i);
		*(str+i)=*(str+(l-1));
		*(str+(l-1))=temp;
		l--;
	}
	return str;

}
