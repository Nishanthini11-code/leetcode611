#include <string.h> // For strlen
#include <stdio.h>  // For printf (optional, for testing)

int numSub(char * s) {
    long long ans = 0;
    int current_consecutive_ones = 0;
    long long mod = 1000000007; // 10^9 + 7

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1') {
            current_consecutive_ones++;
        } else {
            current_consecutive_ones = 0; // Reset count if '0' is encountered
        }
        ans = (ans + current_consecutive_ones) % mod;
    }

    return (int)ans;
}
    
