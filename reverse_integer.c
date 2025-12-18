#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        
        // Check for overflow before multiplying
        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
        
        rev = rev * 10 + pop;
    }
    return rev;
}

// Test function
int main() {
    // Test cases
    printf("123 reversed is: %d\n", reverse(123));        // Should output 321
    printf("-123 reversed is: %d\n", reverse(-123));      // Should output -321
    printf("120 reversed is: %d\n", reverse(120));        // Should output 21
    printf("2147483647 reversed is: %d\n", reverse(2147483647));  // Should output 0 (overflow)
    printf("-2147483648 reversed is: %d\n", reverse(-2147483648)); // Should output 0 (overflow)
    return 0;
}