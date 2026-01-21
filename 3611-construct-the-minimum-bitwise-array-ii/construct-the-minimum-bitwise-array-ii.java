import java.util.List;

class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            int x = nums.get(i);

            if (x == 2) {
                ans[i] = -1;
            } else {
                int bit = 1;
                // find the last continuous set bit from LSB
                while ((x & bit) != 0) {
                    bit <<= 1;
                }
                bit >>= 1; // leading 1 of the last group
                ans[i] = x - bit;
            }
        }
        return ans;
    }
}


        
    
