/* WAP to take an input string from the user, and delete the given word n number of times from a file.
Eg., input : world , 5
Find and delete the word “world” in a file 5 times.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

int main() 
{
	FILE *filePointer;
	char searchWord[MAX_SIZE];
	int deleteCount, wordCount = 0;
	char fileContent[MAX_SIZE];
	char *wordPtr, *tempPtr, *startPtr, *endPtr;
	printf("Enter the word to delete from the file: ");
	scanf("%s", searchWord);
	printf("Enter the number of times to delete '%s' from the file: ", searchWord);
	scanf("%d", &deleteCount);
	filePointer = fopen("data.txt", "r+");
	if (filePointer == NULL) 
		printf("Unable to open file\n");
	fread(fileContent, 1, MAX_SIZE, filePointer);
	fclose(filePointer);
	wordPtr = fileContent;
	while ((tempPtr = strstr(wordPtr, searchWord)) != NULL && wordCount < deleteCount) 
	{
		wordCount++;
		startPtr = tempPtr;
		endPtr = tempPtr + strlen(searchWord);
		while (*endPtr != '\0') 
		{
			*startPtr++ = *endPtr++;
		}
		*startPtr = '\0';
		wordPtr = tempPtr + 1; 
	}
	filePointer = fopen("data.txt", "w");
	if (filePointer == NULL) 
		printf("Unable to open file\n");
	fwrite(fileContent, strlen(fileContent), 1, filePointer);
	fclose(filePointer);
	printf("'%s' deleted %d times from the file successfully.\n", searchWord, wordCount);
	return 0;
}

