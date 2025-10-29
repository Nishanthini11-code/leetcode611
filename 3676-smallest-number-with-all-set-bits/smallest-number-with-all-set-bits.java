class Solution {
    public int smallestNumber(int n) {
        // If n is already of the form 2^k - 1 (all bits set)
        if ((n & (n + 1)) == 0) {
            return n;
        }

        // Find the position of the most significant bit (MSB)
        int k = 0;
        int temp = n;
        while (temp > 0) {
            k++;
            temp >>= 1; // right shift by 1
        }

        // Return number with k bits all set to 1 → (1 << k) - 1
        return (1 << k) - 1;
    }

    // Test the function
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.smallestNumber(5));  // Output: 7
        System.out.println(sol.smallestNumber(10)); // Output: 15
        System.out.println(sol.smallestNumber(3));  // Output: 3
        System.out.println(sol.smallestNumber(1));  // Output: 1
    }
}
