#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    bool* ans = (bool*)malloc(numsSize * sizeof(bool));
    if (ans == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numsSize;

    int current_remainder = 0;
    for (int i = 0; i < numsSize; i++) {
        // Update the current number (mod 5)
        // Shifting left (multiplying by 2) and adding the new bit (nums[i])
        current_remainder = (current_remainder * 2 + nums[i]) % 5;
        
        // Check if the current prefix number is divisible by 5 (remainder is 0)
        ans[i] = (current_remainder == 0);
    }

    return ans;
}

    
