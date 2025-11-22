int minimumOperations(int* nums, int numsSize) {
    int operations = 0;
    for (int i = 0; i < numsSize; i++) {
        int remainder = nums[i] % 3;
        if (remainder != 0) {
            // If remainder is 1, we can either decrement by 1 (1 operation)
            // or increment by 2 (2 operations). So, 1 operation.
            // If remainder is 2, we can either increment by 1 (1 operation)
            // or decrement by 2 (2 operations). So, 1 operation.
            operations++; 
        }
    }
    return operations;
}