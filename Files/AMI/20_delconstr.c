// Delete consonants from a string.

#include<string.h>
#include<stdio.h>
int main()
{
	int i,j=0;
	char str[1000];
	printf("enter the string: ");
	scanf("%[^\n]s",str);
	for(i=0;i<strlen(str);i++)
	{
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			{
				str[j++]=str[i];
			}
		}
		else
		str[j++]=str[i];
	}
	str[j]='\0';
	printf("%s",str);
}
