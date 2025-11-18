#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    while (i < bitsSize - 1) { // Iterate until the second-to-last element
        if (bits[i] == 0) {
            i += 1; // If it's a '0', it's a 1-bit character, advance by 1
        } else { // if (bits[i] == 1)
            i += 2; // If it's a '1', it's the start of a 2-bit character, advance by 2
        }
    }
    // After the loop, if 'i' points to the last element (bitsSize - 1),
    // it means the last character was a 1-bit character.
    return i == bitsSize - 1;
}
    
