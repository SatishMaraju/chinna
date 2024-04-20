// Write a program that reads a string as input, and determines whether the string is a palindrome or not.


#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i=0,l;
	int count=0;
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	l=strlen(a);
	while(a[i])
	{
		if(a[i]==a[l-1-i])
		count++;
	i++;
	}
	if(count==l){
		printf("palindrome");}
	else{

		printf("not a palindrome");}
}
