#include <string.h>

int countCollisions(char * directions) {
    int n = strlen(directions);
    int l = 0;
    int r = n - 1;

    // Trim leading 'L's
    while (l < n && directions[l] == 'L') {
        l++;
    }

    // Trim trailing 'R's
    while (r >= 0 && directions[r] == 'R') {
        r--;
    }

    int collisions = 0;
    // Count collisions in the effective segment
    for (int i = l; i <= r; i++) {
        if (directions[i] != 'S') {
            collisions++;
        }
    }

    return collisions;
}