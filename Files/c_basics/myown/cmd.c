#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int str[100],z;
	char str1[100];
	strcpy(str1,argv[1]);
	int l=strlen(str1);
	for(int i=0;i<l;i++)
	{
		z=str1[i]-48;
		switch(z)
		{
		case 0:printf("zero ");break;
		case 1:printf("one ");break;
		case 2:printf("two ");break;
		case 3:printf("three ");break;
		case 4:printf("four ");break;
		case 5:printf("five ");break;
		case 6:printf("six ");break;
		case 7:printf("seven ");break;
		case 8:printf("eight ");break;
		case 9:printf("nine ");break;
		}
	}
}
