/*5) "Write a function that communicates with main using a single static variable without taking any input arguments.
Everytime function returns something using the static variable,after using it, main sends another input using the same variable and calls the function again.
eg., print the square of each number of an array :
for each number of the array :
call the function
main gets the static variable address as return value from function.
main puts the array element in static variable.
in the function :
create static variable.
if static variable value is not zero, print its square.
function sends static variable address back to main."   */


#include <stdio.h>

int *func();

int main()
{
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	int i;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	int *p;
	p = func();

	for (i = 0; i < size; i++)
	{
		*p = arr[i];
		p = func();
		printf("The square of the array element arr[%d] is %d\n", i, *p);
	}
}

int *func()
{
	static int p;
	if (p != 0)
	{
		p = p * p;
		return &p;
	}
	else
	{
		return &p;
	}
}
