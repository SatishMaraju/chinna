// WAP to implement  


#include <stdio.h>
#include <string.h>

int main() {
	char str[100];
	printf("Enter the string: ");
	scanf(" %[^\n]s", str);
	int l=strlen(str)-1;
	int i,j;
	char temp;
	for(i=0;i<=l;i++)
	{
		temp=str[i];
		str[i]=str[l];
		str[l]=temp;
		l--;
	}
	//printf("%s\n", str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i+1]==' '||str[i+1]=='\0')
		{
			for(j=i;j>=0&&str[j]!=' ';j--)
			{
				printf("%c",str[j]);
			}
			if(str[i+1]==' ')
			{
				printf(" ");
			}
		}
	}
	return 0;
}
