//Write a program to Set, clear and toggle particular bit using bit wise operator?



#include<stdio.h>
void set(int ,int);
void clear(int ,int);
void toggle(int ,int);

int main()
{
	int x,p;
	printf("enter value and position\n");
	scanf("%d%d",&x,&p);
	set(x,p);
	clear(x,p);
	toggle(x,p);}
void set(int x, int p)
{
	printf("%d\n",x|(0x1<<p));
}
void clear(int x,int p)
{
	printf("%d\n",x&(0x1<<p));
}
void toggle(int x,int p)
{
	printf("%d\n",x^(0x1<<p));
}

