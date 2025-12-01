#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For LLONG_MAX

// Helper function to find the minimum of two long long values
long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

// Function to check if 'm' is a feasible running time
bool check(long long m, int n, int* batteries, int batteriesSize) {
    long long total_usable_power = 0;
    for (int i = 0; i < batteriesSize; i++) {
        total_usable_power += min(m, batteries[i]);
    }
    return total_usable_power >= m * n;
}

long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long sum_batteries = 0;
    for (int i = 0; i < batteriesSize; i++) {
        sum_batteries += batteries[i];
    }

    long long low = 0;
    long long high = sum_batteries / n; // Maximum possible average time
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, batteries, batteriesSize)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
    
