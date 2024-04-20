/* Assume that there is a file with 0 to 1000 numbers. Take input of two integers, and replace the first integer with next.
   Eg., 365 ,563
   365 must be replaced everywhere with 563.
 */
#include <stdio.h>
int main() 
{
	int numbers[1001];
	int num1, num2;
	int count=0;
	FILE *fp=fopen("numbers.txt", "r");
	if (fp == NULL)
		printf("open fails\n");
	while (fscanf(fp, "%d", &numbers[count])==1 && count<1001) {
		count++;
	}
	fclose(fp);
	printf("Enter two integers (num1 num2): ");
	scanf("%d %d", &num1, &num2);
	for (int i=0;i<count;i++) {
		if (numbers[i] == num1) {
			numbers[i]=num2;
		}
	}
	fp=fopen("numbers.txt", "w");
	if (fp == NULL)
		printf("open failed\n");
	for (int i=0;i<count;i++) {
		fprintf(fp, "%d ", numbers[i]);
	}
	fclose(fp);
	printf("Numbers replaced successfully in the file.\n");
	return 0;
}

