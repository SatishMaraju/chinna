// WAP to take string as input and print all the subset possibilities.


#include <stdio.h>
#include <string.h>
void generateSubsets(char *str) 
{
	int n = strlen(str);
	int totalSubsets = 1 << n;
	for (int i = 0; i < totalSubsets; i++) 
	{
		printf("{ ");
		for (int j = 0; j < n; j++) 
		{
			if (i & (1 << j)) 
			{
			printf("%c", str[j]);
			}
		}
		printf(" }\n");
	}
}
int main() {
	char str[100];
	printf("Enter a string: ");
	scanf("%s", str);
	printf("All subsets of the string are:\n");
	generateSubsets(str);
	return 0;
}
