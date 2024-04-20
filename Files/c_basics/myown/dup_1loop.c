// WAP to find the duplicates in an array using single loop.


#include <stdio.h>

void findDuplicates(int arr[], int size) 
{
	int c=0;
	int hashSet[1000] = {0}; // Assuming the maximum value in the array is less than 1000
	printf("Duplicates: ");
	for (int i = 0; i < size; i++) 
	{
		if (hashSet[arr[i]] == 1){
			printf("%d ", arr[i]);
			c++;}
		else 
			hashSet[arr[i]] = 1;
	}
	printf("\n");
	printf("count:%d\n",c);
}

int main() 
{
	int arr[] = {1, 2, 3, 4, 5, 3, 6, 7, 8, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	findDuplicates(arr, size);
	return 0;
}
