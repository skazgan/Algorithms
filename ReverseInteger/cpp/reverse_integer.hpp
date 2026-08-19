#ifndef REVERSE_INTEGER_HPP
#define REVERSE_INTEGER_HPP

#include <cstdlib>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;
        long long xAbs = std::abs(static_cast<long long>(x));

        long long result = 0;
        while (xAbs != 0) {
            long long digit = xAbs % 10;
            xAbs /= 10;

            if (result > (INT_MAX - digit) / 10) {
                return 0;
            }

            result = result * 10 + digit;
        }

        result *= sign;
        return (result < INT_MIN || result > INT_MAX) ? 0 : static_cast<int>(result);
    }
};

#endif // REVERSE_INTEGER_HPP
