#include <stdio.h>
#include <ctype.h> // For isdigit()

// Function to count the number of digits in a string
int count_digits(const char *str) {
    int count = 0;
    while (*str != '\0') { // Iterate through the string until the null terminator
        if (isdigit(*str)) { // Check if the current character is a digit
            count++;
        }
        str++; // Move to the next character
    }
    return count;
}

// Function to compare the expected and actual count of digits
int check_string(const char *str) {
    int expected = count_digits(str);
    int actual = asma(str); // Cast to unsigned char* for asma
    if (expected == actual) {
        printf("Test passed\n");
        return 1; // Success
    } else {
        printf("Test failed: Expected %d digits, Actual %d digits\n", expected, actual);
        return 0; // Failure
    }
}

int main() {
    // 10 strings of 64 characters with random digit patterns
    const char *strings[10] = {
        "abc123def456ghi789jkl012mno345pqr678stu901vwx234yzA567BCD890EFG", // Mixed digits and letters
        "1111111111222222222233333333334444444444555555555566666666667777", // All digits
        "NoDigitsHereJustLettersAndSomeSymbols!@#$%^&*()_+{}|:<>?[];',./", // No digits
        "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", // Digits at the start
        "A1B2C3D4E5F6G7H8I9J0K1L2M3N4O5P6Q7R8S9T0U1V2W3X4Y5Z6a7b8c9d0e", // Alternating digits and letters
        "0000000000000000000000000000000000000000000000000000000000000000", // All zeros
        "9999999999999999999999999999999999999999999999999999999999999999", // All nines
        "1a2b3c4d5e6f7g8h9i0j1k2l3m4n5o6p7q8r9s0t1u2v3w4x5y6z7A8B9C0D", // Digits mixed with letters
        "1234567890123456789012345678901234567890123456789012345678901234", // Continuous digits
        "!@#$%^&*()_+{}|:<>?[];',./1234567890abcdefghijklmnopqrstuvwxyz"  // Digits in the middle
    };

    // Test each string
    for (int i = 0; i < 10; i++) {
        printf("Testing string %d: \"%s\"\n", i + 1, strings[i]);
        check_string(strings[i]);
    }

    return 0;
}