class Solution {
    public int minNumberOperations(int[] target) {

       if (target == null || target.length == 0) {
            return 0;
        }

        int operations = target[0]; // The first element always requires target[0] operations to reach its value from 0.

        for (int i = 1; i < target.length; i++) {
            // If the current element is greater than the previous one,
            // we need to add the difference to the total operations.
            // This represents extending a previous increment or starting a new one.
            if (target[i] > target[i - 1]) {
                operations += (target[i] - target[i - 1]);
            }
            // If target[i] <= target[i-1], no additional operations are needed
            // for this specific element to reach its value from the perspective
            // of the previous element, as it can be covered by previous operations.
        }

        return operations;
    }
}
    
