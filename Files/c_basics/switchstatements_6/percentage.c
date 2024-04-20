/*Extend the percentage marks program to print the grade of the student as per below division , using switch statement.
  80 - 100        : Honours
  60 - 79         : First Division
  50 - 59         : Second Division
  40 - 49         : Third Division
  0 - 39          : Fail  */



#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,marks;
	int perc;
	printf("enter the 6 subjects marks:");
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	perc=(a+b+c+d+e+f)/6;
	switch(perc)
	{
		case 80 ... 100:printf("honours");
		break;
		case 60 ... 79:printf("first division");
		break;
		case 50 ... 59:printf("second division");
		break;
		case 40 ... 49:printf("third division");
		break;
		case 0 ... 39:printf("fail");
		break;
		default:("invalid");
	}}

