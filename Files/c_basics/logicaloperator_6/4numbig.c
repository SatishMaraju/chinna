//Read 4 numbers and print which of them is biggest.


#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("enter a,b,c and d\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b&&a>c&&a>d)
	printf("a is big");
	else if(b>a&&b>c&&b>d)
	printf("b is big");
	else if(c>a&&c>b&&c>d)
	printf("c is big");
	else
	printf("d is big");
return 0;
}
