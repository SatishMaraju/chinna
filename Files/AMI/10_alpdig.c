/* Take string from user and count no of alphabets, digits and blank spaces.
   i/p=”abc ff 123f xyz”     
   output= alphabets : 9, digits=3, spaces=3
 */

#include<string.h>
#include<stdio.h>
int main()
{
	char str[1000];
	int a=0,d=0,s=0;
	printf("enter the string: ");
	scanf("%[^\n]s",str);
	for(int i=0;i<strlen(str);i++)
	{
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
			a++;
		else if(str[i]>='0'&&str[i]<='9')
			d++;
		else if(str[i]==' ')
			s++;
		else;
	}
	printf("%d\t%d\t%d\n",a,d,s);
}
