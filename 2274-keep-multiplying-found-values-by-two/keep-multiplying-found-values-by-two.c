#include <stdbool.h> // Required for boolean type

int findFinalValue(int* nums, int numsSize, int original) {
    // Create a boolean array to mark the presence of numbers up to 1000.
    // Constraints state nums[i] and original are <= 1000.
    bool found[1001] = {false}; 

    // Populate the 'found' array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 1000) { // Ensure within bounds
            found[nums[i]] = true;
        }
    }

    // Keep multiplying 'original' by two as long as it's found
    while (original <= 1000 && found[original]) {
        original *= 2;
    }

    return original;
}
    
