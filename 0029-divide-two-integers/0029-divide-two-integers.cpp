class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to safely handle INT_MIN
        long long a = dividend;
        long long b = divisor;

        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        long long quotient = 0;

        // Binary division
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Find largest power of 2 multiple of divisor
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest possible multiple
            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative)
            quotient = -quotient;

        // Clamp to 32-bit range
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};