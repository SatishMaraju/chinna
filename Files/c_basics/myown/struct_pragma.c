typedef struct student{
#pragma pack(1)
	char ch;
	int a;
	char ch1;
	float f;
}stu;

#include <stdio.h>
int main()
{
	char ch;
	printf("%ld",sizeof(stu));
	return 0;
}


// Comnclusion: Without pragma the size is 16 bytes. After including pragma the size is 10 bytes.
