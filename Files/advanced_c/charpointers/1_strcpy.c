/* 1) Implement your own string copy function.
   try calling the string copy function by sending the below as input:
   1) string constant as destination and string variable as source
   2) string variable as destination and string constant as source
   3) string variable as destination and string variable as source
   4) string constant as destination and string constant as source
   note down the output and analyze the reasons.
 */


#include<stdio.h>
#include<string.h>
void myownstrcpy(char *ptr,char *ptr1);
int main()
{
	char str[10];
	char str1[10];
	printf("Enter the contents of source  str:");
	scanf("%[^\n]s",str);
	myownstrcpy( str,str1);
	return 0;
}

void myownstrcpy(char *ptr,char *ptr1)
{
	int i=0;
	while(str[i])
	{
		str1[i]=str[i];
		i++;
	}
	str1[i]='\0';
	printf("The destination string is : %s",str1);

}
