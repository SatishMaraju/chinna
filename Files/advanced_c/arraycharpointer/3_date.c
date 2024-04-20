/*   read a date in d-m-y format and print it back in given format below:

eg input :2-3-2000
output: 2nd March, 2000

eg input: 4-1-2001
output: 4th January, 2001
*/


#include<stdio.h>
#include<string.h>

int main()
{
	int d,m,y;
	printf("enter date: "); 
	scanf("%d/%d/%d",&d,&m,&y);
	char *mon[12]={"january","febuary","march","april","may","june","july","august","september","october","novmber","december"};
	char *s[5]={"th","st","nd","rd","th"};
	printf("output: "); 
	printf("%d",d);
	if(d==11||d==12||d==13)
		printf("%s ",s[0]);
	else
	{
		d=d%10;
		if(d>3)
			d=3;
		printf("%s ",s[d]);
	}

	m=m-1;
	printf("%s, ",mon[m]);
	printf("%d",y);
	printf("\n");

}
