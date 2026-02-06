// Remove Duplicates from Sorted Array
#include <stdio.h>

int main() {
    int arr[100], n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for (i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = arr[n - 1];  // last element
    j++;

    printf("Array after removing duplicates:\n");
    for (i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
