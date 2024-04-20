/*  int palindrome (char str[])
    return 1 if the given string is a palindrome, return 0 if it is not a palindrome     */


#include<stdio.h>
#include<string.h>
int palindrome(char a[]);
int main()
{
	int s;
	char a[1000];
	printf("enter the string\n");
	scanf("%[^\n]s",a);
	s=palindrome(a);
	if(s==1){
		printf("palindrome");}
	else{

		printf("not a palindrome");}
}

int palindrome(char a[])
{
	int i=0,count=0;
	int l=strlen(a);
	while(a[i])
	{
		if(a[i]==a[l-1-i]){
		i++;
		return 1;}
		else{
		return 0;}}}
