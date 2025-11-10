import java.util.Stack;

class Solution {
    public int minOperations(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int operations = 0;

        for (int num : nums) {
            // Remove elements from the stack that are greater than the current number
            while (!stack.isEmpty() && stack.peek() > num) {
                stack.pop();
            }

            // If the stack is empty or the top element is different from the current number
            if (stack.isEmpty() || stack.peek() != num) {
                if (num != 0) { // Only count operations for non-zero numbers
                    operations++;
                    stack.push(num);
                }
            }
        }

        return operations;
    }
}

        
    
