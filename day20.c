//Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define OFFSET 1000000   // To handle negative sums safely

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long prefix_sum = 0;

    // Large frequency array to store prefix sums
    int *freq = (int*)calloc(2 * OFFSET + 1, sizeof(int));

    // Prefix sum = 0 initially appears once
    freq[OFFSET] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(prefix_sum + OFFSET >= 0 && prefix_sum + OFFSET <= 2 * OFFSET) {
            count += freq[prefix_sum + OFFSET];
            freq[prefix_sum + OFFSET]++;
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}