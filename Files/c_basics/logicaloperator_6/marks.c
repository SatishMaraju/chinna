/*Find the % of marks for 6 subjects (read 6 subject marks and calculate percentage), for a student, and print the grade of the student as per below division , using if else statement and typecasting operator to get perfect floating point percentage.
80 - 100        : Honours
60 - 79         : First Division
50 - 59         : Second Division
40 - 49         : Third Division
0 - 39          : Fail    */



#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	float per;
	printf("enter the 6 subjects marks:\n");
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	per=(a+b+c+d+e+f)/6;
	if(per>=80&&per<=100)
	printf("honours");
	else if(per>=60&&per<=79)
	printf("first division");
	else if(per>=50&&per<=59)
	printf("second division");
	else if(per>=40&&per<=49)
	printf("third division");
	else
	printf("fail");
	return 0;
}
