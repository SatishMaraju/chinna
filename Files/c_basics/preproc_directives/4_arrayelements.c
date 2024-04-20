/*    Define  a macro that receives an array and the number of elements in the array as arguments. Write a program using this macro to print out the elements of the array. Try using this macro for different data types of arrays.    */



#define ARRAY(arr,n) arr[n]

#include<stdio.h>
int main()
{
	int a1[10];
	for(int i=0;i<10;i++)
	{
		scanf("%d",&ARRAY(a1,i));
	}
	for(int i=0;i<10;i++)
	{
		printf("%d",ARRAY(a1,i));
	}
	printf("\n");
	float a2[10];
	for(int i=0;i<10;i++)
	{
		scanf("%f",&ARRAY(a2,i));
	}
	for(int i=0;i<10;i++)
	{
		printf("%f",ARRAY(a2,i));
	}
	printf("\n");
	char a3[10];
	for(int i=0;i<10;i++)
	{
		scanf(" %c",&ARRAY(a3,i));
	}
	for(int i=0;i<10;i++)
	{
		printf("%c",ARRAY(a3,i));
	}
	printf("\n");
	return 0;
}

