//write a program to read a date in the below format, and print it back in another format:




#include<stdio.h>
int main()
{
	int dd,mm,yyyy;
	printf("enter the dd-mm-yyyy");
	scanf("%d-%d-%d",&dd,&mm,&yyyy);
	printf("the result is %d/%d/%d",dd,mm,yyyy);
	return 0;
}
