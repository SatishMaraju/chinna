/* Take a string (with spaces), and a character as input. Count the number of occurrences of character inside the string.                                                                                        

IP: “abc 2ff 12 ac2”                       , ‘a’

o/p : no of a’s in given string is ‘2’
 */


#include<stdio.h>
#include<string.h>
int main()
{
	int c=0;
	char str[1000];
	char ch;
	printf("enter the string: ");
	scanf("%[^\n]s",str);
	printf("enter the charecter: ");
	scanf(" %c",&ch);
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]==ch)
			c++;
	}
	printf("%d",c);
}
