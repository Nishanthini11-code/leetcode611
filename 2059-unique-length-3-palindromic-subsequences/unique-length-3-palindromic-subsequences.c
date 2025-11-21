#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // For malloc, free

int countPalindromicSubsequence(char * s) {
    int n = strlen(s);
    int ans = 0;

    // Arrays to store the first and last occurrences of each character
    int first_occurrence[26];
    int last_occurrence[26];

    // Initialize first_occurrence with -1 (not found) and last_occurrence with -1
    for (int i = 0; i < 26; i++) {
        first_occurrence[i] = -1;
        last_occurrence[i] = -1;
    }

    // Find first and last occurrences of each character
    for (int i = 0; i < n; i++) {
        int char_idx = s[i] - 'a';
        if (first_occurrence[char_idx] == -1) {
            first_occurrence[char_idx] = i;
        }
        last_occurrence[char_idx] = i;
    }

    // Iterate through each possible outer character 'a' to 'z'
    for (int i = 0; i < 26; i++) {
        int first_idx = first_occurrence[i];
        int last_idx = last_occurrence[i];

        // If the character appears at least twice and with at least one character in between
        if (first_idx != -1 && last_idx != -1 && last_idx - first_idx > 1) {
            bool unique_chars_in_between[26] = {false}; // To track unique middle characters
            int count_unique_middle = 0;

            // Iterate through the substring between first_idx and last_idx
            for (int j = first_idx + 1; j < last_idx; j++) {
                int middle_char_idx = s[j] - 'a';
                if (!unique_chars_in_between[middle_char_idx]) {
                    unique_chars_in_between[middle_char_idx] = true;
                    count_unique_middle++;
                }
            }
            ans += count_unique_middle;
        }
    }
    return ans;
}