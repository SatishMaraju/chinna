// Write the important mcq on printf statement


#include <stdio.h>
#include <string.h>
void main()
{
	int i=0;
	for(;i++;printf("%d",i));  // printf() statement at the place of inc/dec place is won't be executed
	printf("%d",i);            // 1
	printf("hello chinna\n");  // hello chinna
}
