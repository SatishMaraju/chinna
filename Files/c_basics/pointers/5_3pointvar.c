/*   Declare 3 pointer variables of integer type, and an integer variable. Assign the address of integer variable to the 3 pointers. Print the variable value using indirection on each pointer variable. Change the variable value directly and check the values of each of the pointers using indirection. Change the variable value , using each pointer and print the variable value and indirected values of all pointers every time you change.   */


#include<stdio.h>
int main()
{
	int a;
	printf("enter a:");
	scanf("%d",&a);
	int *p1=&a;
	printf("%d\t",*p1);
	int *p2=&a;
	printf("%d\t",*p2);
	int *p3=&a;
	printf("%d\n",*p3);
	a=20;
	p1=p2=p3=&a;
	printf("%d\t",*p3);
	printf("%d\t",*p3);
	printf("%d\n",*p3);
	*p1=30;
	printf("%d\t",*p1);
	printf("%d\t",*p2);
	printf("%d\n",*p3);
	*p2=40;
	printf("%d\t",*p1);
	printf("%d\t",*p2);
	printf("%d\n",*p3);
	*p3=50;
	printf("%d\t",*p1);
	printf("%d\t",*p2);
	printf("%d\n",*p3);

}
