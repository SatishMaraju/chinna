 Read a 4 digit integer into a variable, using scanf and print it in the below format using escape sequences.
eg., input: 3467

output : 
3
34
346
3467

3
  4
     6
        7






#include<stdio.h>
int main()
{
	int a=3467;
	printf("%d\b\b\b   \n",a);
	printf("%d\b\b  \n",a);
	printf("%d\b \n",a);
	printf("%d\n",a);

	printf("%d\b\b\b   \n",a);
	printf("%d\b\b  \b\b\b\b \n",a);
	printf("%d\b \b\b\b\b  \n",a);
	printf("%d\b\b\b\b   \n",a);
	return 0;
}
