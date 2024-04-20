// WAP to print if the user input is equals to the sum of the subarray or not and also print the sub array and ignored elements.


#include <stdio.h>
#define MAX_SIZE 100
int isSubsetSum(int arr[], int n, int sum, int include[], int *included_count) {
    if (sum == 0) {
        return 1;
    }
    if (n == 0 && sum != 0) {
        return 0;
    }
    if (arr[n - 1] > sum) {
        return isSubsetSum(arr, n - 1, sum, include, included_count);
    }
if (isSubsetSum(arr, n - 1, sum, include, included_count)) {
        return 1;
    }
    include[*included_count] = arr[n - 1];
    (*included_count)++;
    if (isSubsetSum(arr, n - 1, sum - arr[n - 1], include, included_count)) {
        return 1;
    }
    (*included_count)--;
    return 0;
}

int main() {
    int n, i, sum;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum to check for: ");
    scanf("%d", &sum);
    int include[MAX_SIZE];
    int included_count = 0;
    if (isSubsetSum(arr, n, sum, include, &included_count)) {
        printf("Yes, there exists a subset with the sum %d.\n", sum);
        printf("The subset elements are: ");
        for (i = 0; i < included_count; i++) {
            printf("%d ", include[i]);
        }
        printf("\n");
        printf("The ignored elements are: ");
        for (i = 0; i < n; i++) {
            int found = 0;
            for (int j = 0; j < included_count; j++) {
                if (arr[i] == include[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
    } else {
        printf("No, there is no subset with the sum %d.\n", sum);
    }
    return 0;
}
