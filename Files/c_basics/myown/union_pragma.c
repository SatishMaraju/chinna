typedef union student
{
	char ch;
	int a;
	char ch1;
	float f;

}stu;

#include <stdio.h>
int main()
{
	printf("%ld",sizeof(stu));
	return 0;
}

// Comnclusion: It takes higher bytes of memory so the size is 4 bytes.
