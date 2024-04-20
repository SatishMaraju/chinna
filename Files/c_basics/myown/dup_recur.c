// WAP to delete the duplicates in an array using recursion.


#include <stdio.h>
int c=0;
int checkDup(int arr[],int size,int x,int z)
{
	if (x >= size)
		return 0; // No duplicate found
	if (x != z && arr[x] == arr[z])
		return arr[x];
	return checkDup(arr, size, x + 1, z);
}
void findDup(int arr[], int size, int z)
{
	if (z >= size)
		return;
	int dup=checkDup(arr,size,0,z);
	if (dup != 0){
		printf("Duplicate: %d\n",dup);c++;}
	findDup(arr,size,z+1);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 9, 3, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Duplicates :\n");
	findDup(arr,size,0);
	printf("count:%d\n",c);
	return 0;
}
