/* Write a program that opens a file with some number of characters written in it.
   An integer input is taken. If the input is positive, skip those many characters and print the remaining till end of the file. If the input is negative, then print those man y characters till end of the file.
   eg., file contents :abcdefghijklmnopqrstuvwxyz
   input number: 15, output: pqrstuvwxyz
   input number: -10 , output: qrstuvwxyz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
	FILE *fp;
	char data[100];
	int count,fileSize,i;
	fp = fopen("file.txt","r");
	if (fp == NULL) 
	printf("open fail\n");
	fgets(data,1000,fp);
	fileSize = strlen(data);
	fclose(fp);
	printf("Enter number: ");
	scanf("%d",&count);
	if (count > 0) 
	{
		if (count < fileSize) 
		{
		for (i=count;i<fileSize;i++) 
		printf("%c",data[i]);
		}
		else 
		printf("count exceeds file size\n");
	} 
	else if (count < 0) 
	{
		for (i = fileSize + count; i < fileSize; i++) 
		printf("%c", data[i]);
	} 
	else 
		printf("count cannot be zero\n");
	return 0;
}
