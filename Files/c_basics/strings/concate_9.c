/*  void strcat( char d[] , char s[]);

    concatenates the content from source string to the end of destination string ( copy paste characters from s to  d , from null character index in d )
    eg., char d[] = "Kernel";
    char s[] = "Masters";

output: after concatenation d[] becomes " KernelMasters";   */


#include<stdio.h>
#include<string.h>
void mystrcat(char s[],char d[]);
int main()
{
	char s[1000],d[1000];
	printf("enter the source and destination strings\n");
	scanf(" %[^\n]s",s);
	scanf(" %[^\n]s",d);
	mystrcat(s,d);
}

void mystrcat(char d[],char s[])
{
	int i,l;
	l=strlen(s);
	for(i=0;s[i]!=0;i++)
	{
		d[l]=s[i];
		l++;
	}
	printf("%s",d);
}
