/* Write a program trim the spaces in given string. Using following functions
   trim, rtrim, ltrim.
Ex: input "    hello world.   "
rtrim- "hello world.   "
ltrim- "    hello world"
trim- "hello world".
 */


#include<stdio.h>
#include<string.h>
char *myltrim(char *str);
char *myrtrim(char *str);
int main()
{
	char str[1000];
	printf("enter the string: ");
	scanf("%[^\n]s",str);
	myltrim(str);

	printf("%s",myltrim(str));
	printf("\n%s",myrtrim(str));
	mytrim(str);
}
char *myltrim(char *str)
{
	int j=0,i;
	for(i=0;*(str+i)!='\0';i++)
	{
		*(str+j++)=*(str+i);
		if((*(str+i)>='a'&&*(str+i)<='z'||*(str+i)>='A'&&*(str+i)<='Z')&&(*(str+i+1)==' '||(*(str+i+1)=='\t')))
		{
			*(str+j++)=*(str+i);
			break;
		}
		else;
	}
	*(str+j)='\0';
	return str;
}

char *myrtrim(char *ptr)
{
	int k=0,i,l=0;
		for(i=0;i<*(str+i)!=0;i++){
		if((*(ptr+i)>='a'&&*(ptr+i)<='z')||(*(ptr+i)>='A'&&*(ptr+i)<='Z')||(*(ptr+i)>='0'&&*(ptr+i)<='9'))
		{
		break;
		}}
		for(int k=i;*(ptr+k)!=0;k++)
		{
			*(ptr+l++)=*(ptr+k);
		}
	*(ptr+l)='\0';
	return ptr;
}

char *mytrim(char *ltr)
{
myltrim(ltr);
myrtrim(ltr);
return ltr;
}
