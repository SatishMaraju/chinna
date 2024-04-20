// WAP to use the function pointer as the member of the structure.


#include <stdio.h>

struct student
{
int (*fun)(int, int);
};

int add(int a, int b)
{
return a + b;
}

int sub(int a, int b)
{
return a - b;
}

int main()
{
	struct student s;
	s.fun = add;
	int t_add = s.fun(10, 5);
	s.fun = sub;
	int t_sub = s.fun(10, 5);
	printf("Addition: %d\n", t_add);
	printf("Subtraction: %d\n", t_sub);
	return 0;
}
