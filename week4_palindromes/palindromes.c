#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool isPalindrome(char* s);

bool isPalindrome(char* s) {
    // Makes search O(n/2+1) instead of O(n)
    int palLen = strlen(s) / 2 + 1;

    for (int i = 0; i < palLen; i++) {

        char t = s[i]; // Temp

        // Yes, it works.
        asm (
            "cmp %0, %1\n\t" // Compare two ints
            "je true\n\t"    // Jump to true if they're equal
            "add $1, 0\n\t"  // Add 1 to t
            "true:\n\t"
            : "=r"(t)
            : "r"(s[strlen(s)-i-1])
            : "cc"
        );

        // If t is greater than it's original value, we know
        // this can't be a palindrome (due to asm code)
        if (t > s[i]) {
            return false;
        }
    }

    return true;

}

// See if the first command line argument is a palindrome
void main(int argc, char ** argv) {
    printf((isPalindrome(argv[1])) ? "True\n" : "False\n");
}
