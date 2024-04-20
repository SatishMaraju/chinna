/*   Declare an integer array of size 10 and initialize it to some values. Print the addresses of each element of the array using a pointer. using indirection operator , print the value stored in each element of the array.   */


#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},i,*p;
	for(i=0;i<10;i++)
	{
		p=&a[i];

		printf("%p\n",p);
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}}
