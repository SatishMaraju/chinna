/*  Write a program to swap two arrays in reverse order.
    eg.,
input : array1 = {1,2,3,4,5};
array2 = {6,7,8,9,10};
output:

array1 : {10,9,8,7,6}
array2: { 5,4,3,2,1}   */

#include <stdio.h>
int main() {
	int m, i, t = 0;
	printf("Enter size: ");
	scanf("%d", &m);
	int arr1[m];
	int arr2[m];
	int arr3[m];
	printf("Enter for array 1: ");
	for (i = 0; i < m; i++)
		scanf("%d", &arr1[i]);
	printf("Enter for array 2: ");
	for(i=0;i<m;i++)
		scanf("%d",&arr2[i]);
	for(i=0;i<=m;i++)
		arr3[i]=arr1[i];
	for(i=0;i<=m/2;i++)
		arr1[i]=arr2[m-1-i];
	for(i=0;i<=m/2;i++)
		arr2[i]=arr3[m-1-i];
	for(i=0;i<m;i++)
		printf("%d ", arr1[i]);
		printf("\n");
	for(i=0;i<m;i++)
		printf("%d ", arr2[i]);
	return 0;
}
