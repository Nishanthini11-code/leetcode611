#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int findMaxForm(char **strs, int strsSize, int m, int n) {
    // dp[i][j] = max number of strings that can be formed
    // using at most i zeros and j ones.
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc((n + 1), sizeof(int)); // Initialize with zeros
    }

    for (int k = 0; k < strsSize; k++) {
        char *s = strs[k];
        int zeros = 0;
        int ones = 0;

        // Count zeros and ones in the current string
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') zeros++;
            else if (s[i] == '1') ones++;
        }

        // Traverse backwards to prevent reusing the same string
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }

    int result = dp[m][n];

    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

    
