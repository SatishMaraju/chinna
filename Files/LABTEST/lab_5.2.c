/*   WAP to perform operation like below

arr[]={1,2,3,1,4,4,8}  */

#include <stdio.h>

int main() {
    int i, c = 1, maxCount = 1, size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < size; i++) {
        if (arr[i] >= arr[i - 1]) {
            c++;
        } else {
            if (c > maxCount) {
                maxCount = c;
            }
            c = 1;
        }
    }

    if (c > maxCount) {
        maxCount = c;
    }

    printf("The length of the longest sorted array is %d\n", maxCount);
    
    return 0;
}
