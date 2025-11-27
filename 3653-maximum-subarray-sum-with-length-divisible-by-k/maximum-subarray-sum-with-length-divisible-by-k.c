#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For LONG_MIN and LONG_MAX

long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long ans = LONG_MIN;
    long long prefix = 0;

    // minPrefix[i % k] stores the minimum prefix sum encountered so far
    // such that its index modulo k is i % k.
    // Initialize with a very large value to represent infinity.
    long long* minPrefix = (long long*)malloc(k * sizeof(long long));
    for (int i = 0; i < k; ++i) {
        minPrefix[i] = LONG_MAX / 2; // Use a large value to avoid overflow with additions
    }

    // The base case: a prefix sum of 0 at index -1 (conceptually) has a remainder of (k-1) % k.
    // This allows for subarrays starting from index 0.
    minPrefix[(k - 1) % k] = 0; 

    for (int i = 0; i < numsSize; ++i) {
        prefix += nums[i];

        // The current subarray sum ending at 'i' with length divisible by 'k'
        // is `prefix - minPrefix[i % k]`.
        // We want to maximize this difference.
        if (prefix - minPrefix[i % k] > ans) {
            ans = prefix - minPrefix[i % k];
        }

        // Update the minimum prefix sum for the current remainder.
        if (prefix < minPrefix[i % k]) {
            minPrefix[i % k] = prefix;
        }
    }

    free(minPrefix); // Free allocated memory
    return ans;
}
    
