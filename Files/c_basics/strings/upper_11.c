/*  void strupr (char str[]);
 convert all lower case alphabets to upper case in the given string.   */


#include<stdio.h>
#include<string.h>
void mystrupr();
int main()
{
	char a[10];
	int s;
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	mystrupr(a);
}
void mystrupr(char a[])
{
	int i;
	int l;
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if((a[i]>=97)&&(a[i]<=122))
		a[i]=a[i]-32;
	}
printf("%s",a);
}

