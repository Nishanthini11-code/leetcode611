#include <stdbool.h>
#include <stddef.h> // For size_t

bool kLengthApart(int* nums, int numsSize, int k) {
    int lastOneIndex = -1; // Initialize to -1 to indicate no '1' has been found yet

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (lastOneIndex != -1) { // If a previous '1' was found
                if (i - lastOneIndex - 1 < k) { // Check distance
                    return false; // Not k places away
                }
            }
            lastOneIndex = i; // Update the index of the last found '1'
        }
    }
    return true; // All '1's are at least k places away
}
    
