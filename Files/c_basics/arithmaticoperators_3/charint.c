/* Input 3 digits, read them into three different characters. Make one integer out of them and display.
Eg., input 345.(stored as char c =‘3’,b=‘4’,d=‘5’.)
Output : int i = 345. ( store 345 in integer i and print the value of i as output).

hint: any digital character can be converted to a corresponding digit by subtraction with '0'.*/





#include<stdio.h>
int main()
{
	int a,b,c,i;
	char x,y,z,u='0';
	printf("enter x,y,z:");
	scanf("%c %c %c",&x,&y,&z);
	a=x-u;
	b=y-u;
	c=z-u;
	i=a*100+b*10+c;
	printf("%d\n",i);
	return 0;
}
