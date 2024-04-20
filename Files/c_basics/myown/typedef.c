#include<stdio.h>
int main()
{
	typedef int in;
	typedef char ch;
	typedef float fl;
	typedef double du;
	in a;
	ch c;
	fl f;
	du d;
	printf("enter the values\n");
	scanf("%d %c %f %lf",&a,&c,&f,&d);
	printf("%d\t %c\t %f\t %lf\n",a,c,f,d);
}

