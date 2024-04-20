/*   Declare 3 integer variables. Declare an integer pointer. Assign the address of each variable to the pointer in succession and print the value of the variable using indirection operator on the pointer.     */


#include<stdio.h>
int main()
{
	int a,b,c;
	printf("entter a,b and c:\n");
	scanf("%d%d%d",&a,&b,&c);
	int *p=&a;
	printf("%d\n",*p);
	p=&b;
	printf("%d\n",*p);
	p=&c;
	printf("%d\n",*p);
}
