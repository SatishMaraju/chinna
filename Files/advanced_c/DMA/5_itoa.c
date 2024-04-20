//  Implement itoa function and return the string from the function. Print the result in main. itoa function takes an integer as input, and stores the integer in a string.


#include<stdio.h>
#include<stdlib.h>

	char *itoa(int);
	int main()
	{
		int num;
		printf("Enter integer: ");
		scanf("%d", &num);

		char *a = itoa(num);

		printf("string:%s", a);

		free(a);

		return 0;
	}

	char *itoa(int num)
	{
		int temp = num, count=0;
		while(temp)
		{
		temp=temp/10;
		count++;
		}

		char *str = (char *)malloc((count+1)*sizeof(char));
		if (str == NULL)
		{
		printf("Memory allocation failed\n");
		exit(1);
		}

		int i=0;
		while(num)
		{
		str[i] = num%10 + '0';
		num = num/10;
		i++;
		}

		for (int j = 0; j < i / 2; j++)
		{
		char temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		}
		str[i+1] = '\0';

		return str;
	}
