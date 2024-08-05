#include <limits.h> // For INT_MAX and INT_MIN
#include <cstdlib>  // For abs()

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool sign = (dividend < 0) == (divisor < 0);

        // Convert both numbers to positive using long to handle abs(INT_MIN)
        long n = labs(dividend), d = labs(divisor);
        long ans = 0;

        while(n >= d) {
            int count = 0;
            while(n >= (d << (count + 1))) {
                count++;
            }
            ans += (1 << count);
            n -= (d << count);
        }

        // If the result should be negative, flip the sign
        return sign ? ans : -ans;
    }
};
