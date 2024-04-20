//5) int strncmp(char s1[]. char s2[], int n);//




#include <stdio.h>
#include <string.h>

int myownstrcmp(const char *str1, const char *str2, int n);

int main() {
	int n;
	char str1[100];
	char str2[100];
	int c = 0;

	printf("Enter the 2 strings\n");
	scanf("%[^\n]s", str1);
	scanf(" %[^\n]s", str2);
	printf("Enter the length\n");
	scanf("%d", &n);

	c = myownstrcmp(str1, str2, n);
		if (c == 0)
			printf("Both are equal\n");
		else if (c == 1){
			printf("Both are not equal\n");
	} else {
		printf("Both are not equal\n");
	}

	return 0;
}
int myownstrcmp(const char *str1, const char *str2, int n) {
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (*(str1 + i) == *(str2 + i)) {
			c = 0;
		}
		else
		c=1;
	}

	return c;
}
