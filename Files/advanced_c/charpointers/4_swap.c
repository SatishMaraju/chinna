//4) Write a swap function to swap the values of two character variables.

#include<stdio.h>
#include<string.h>
void my(char *s,char *d);
int main()
{

	char s,d;
	printf("char 1 : ");
	scanf(" %c",&s);
	printf("char 2 : ");
	scanf(" %c",&d);
	char *s1=&s,*d1=&d;
	
        my(s1,d1);
	printf("char 1 : %c\n",s);
	printf("char 2 : %c\n",d);

}

void my(char *s,char *d)
{	
	char c;
	c=*s;
	*s=*d;
	*d=c;
}
