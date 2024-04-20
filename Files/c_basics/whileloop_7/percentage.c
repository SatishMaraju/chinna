/*read the 6 subject scores of n students, calculate their percentage, and print the grade of each student based on % using below slabs:
80 - 100        : Honours
60 - 79         : First Division
50 - 59         : Second Division
40 - 49         : Third Division
0 - 39          : Fail  */



#include<stdio.h>
int main()
{
	int i=1,n,a,b,c,d,e,f,perc;
	printf("enter n value:");
	scanf("%d",&n);
	while(i<=n)
	{
	printf("enter 6 sub marks:");
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	perc=(a+b+c+d+e+f)/6;
	switch(perc)
	{
	case 80 ... 100:printf("honours\n");break;
	case 60 ... 79:printf("first division\n");break;
	case 50 ... 59:printf("second division\n");break;
	case 40 ... 49:printf("third division\n");break;
	case 0 ... 39:printf("fail\n");break;
	default:printf("nothing");
	}
	i++;
}}
