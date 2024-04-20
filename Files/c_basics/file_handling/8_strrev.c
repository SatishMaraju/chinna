// Write a program to write a set of characters to a file, and read and print the contents in reverse.


/* Write a program to write a set of characters to a file, and read and print the contents in reverse.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	FILE *fp;
	char data[100];
	int i,temp=0;
	fp = fopen("char.txt","w");
	if (fp == NULL) 
		printf("error in creating file\n");
	printf("enter text to write into file\n");
	fgets(data,100,stdin);
	fprintf(fp,"%s",data);
	fclose(fp);
	fp = fopen("char.txt","r");
	if (fp == NULL) 
		printf("open fail\n");
	while (fgets(data,100,fp) != NULL) 
		temp += strlen(data);
	printf("Content of the file in reverse");
	for (i=temp-1;i>=0;i--) 
	{
		fseek(fp,i,SEEK_SET);
		printf("%c",fgetc(fp));
	}
	printf("\n");
	fclose(fp);
	return 0;
}
