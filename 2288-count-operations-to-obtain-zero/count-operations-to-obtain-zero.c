int countOperations(int num1, int num2) {
    int operations = 0; // Initialize a counter for operations

    // Continue as long as both numbers are non-zero
    while (num1 != 0 && num2 != 0) {
        if (num1 >= num2) {
            num1 -= num2; // Subtract num2 from num1 if num1 is greater or equal
        } else {
            num2 -= num1; // Subtract num1 from num2 if num2 is greater
        }
        operations++; // Increment the operation counter
    }

    return operations; // Return the total number of operations
}
    
