/* WAP to print like below format
input: 12345
output:Twelve thousand three hundred fourty five
 */


#include <stdio.h>

void convert_to_rupees(int n) {
	// Define arrays for mapping numbers to words
	char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	// Function to convert numbers to words
	void convert_chunk(int num) {
		if (num == 0)
			return;
		else if (num < 10)
			printf("%s ", ones[num]);
		else if (num < 20)
			printf("%s ", teens[num - 10]);
		else if (num < 100) {
			printf("%s ", tens[num / 10]);
			convert_chunk(num % 10);
		} else if (num < 1000) {
			printf("%s hundred ", ones[num / 100]);
			convert_chunk(num % 100);
		} else if (num < 100000) {
			convert_chunk(num / 1000);
			printf("thousand ");
			convert_chunk(num % 1000);
		} else if (num < 10000000) {
			convert_chunk(num / 100000);
			printf("lakh ");
			convert_chunk(num % 100000);
		}
	}

	// Main function logic
	if (n == 0) {
		printf("zero");
	} else {
		convert_chunk(n);
	}
}

int main() {
	int number;
	printf("Enter an integer: ");
	scanf("%d", &number);
	printf("Output: ");
	convert_to_rupees(number);
	printf("\n");
	return 0;
}
