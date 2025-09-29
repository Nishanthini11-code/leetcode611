class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // dp[i][j] stores the minimum score to triangulate the polygon
        // formed by vertices from index i to j (inclusive).
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Iterate through possible lengths of sub-polygons (from 3 to n)
        for (int length = 3; length <= n; ++length) {
            // Iterate through all possible starting vertices 'i'
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1; // Ending vertex 'j'

                // Initialize dp[i][j] with a very large value
                dp[i][j] = INT_MAX;

                // Iterate through all possible 'k' that can form a triangle (i, k, j)
                // 'k' must be between i+1 and j-1
                for (int k = i + 1; k < j; ++k) {
                    // The score for the triangle (i, k, j) is values[i] * values[k] * values[j]
                    // We add the minimum scores of the sub-polygons (i, k) and (k, j)
                    dp[i][j] = std::min(dp[i][j], 
                                        values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]);
                }
            }
        }

        // The result is the minimum score to triangulate the entire polygon (from 0 to n-1)
        return dp[0][n - 1];
    }
};