#include <stdio.h>
#include <math.h>

int main() {
    // Using pow() function
    double base = 2.0;
    double exponent = 3.0;
    double result = pow(base, exponent);
    printf("%.2f raised to the power %.2f = %.2f\n", base, exponent, result);

    // Integer exponents using pow()
    int int_base = 2;
    int int_exponent = 3;
    int int_result = (int)pow(int_base, int_exponent);
    printf("%d raised to the power %d = %d\n", int_base, int_exponent, int_result);

    // Manual calculation for positive integer exponents
    int manual_result = 1;
    for(int i = 0; i < int_exponent; i++) {
        manual_result *= int_base;
    }
    printf("Manual calculation: %d raised to the power %d = %d\n", int_base, int_exponent, manual_result);

    // Some other common operations
    printf("\nOther common operations:\n");
    printf("Square root of 16: %.2f\n", sqrt(16.0));    // Square root using sqrt()
    printf("Cube root of 27: %.2f\n", cbrt(27.0));      // Cube root using cbrt()
    printf("e raised to power 2: %.2f\n", exp(2.0));     // e^x using exp()

    return 0;
} 