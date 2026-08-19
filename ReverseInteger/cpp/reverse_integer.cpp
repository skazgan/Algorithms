/**
 * Reverse Integer
 * ----------------
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer
 * range [-2^31, 2^31 - 1], return 0 instead.
 *
 * Example:
 *   Input:  x = 123
 *   Output: 321
 *
 *   Input:  x = -123
 *   Output: -321
 *
 *   Input:  x = 120
 *   Output: 21
 *
 *   Input:  x = 1534236469
 *   Output: 0   (reversed digits would be 9646324351, which overflows)
 *
 * Approach: digit-by-digit extraction, with overflow checked before it happens
 *   Strip the sign, then repeatedly peel off the last digit of x (x % 10)
 *   and build up the reversed number one digit at a time (result * 10 +
 *   digit). Before every multiply, check whether it would push the result
 *   past the signed 32-bit limit -- checking beforehand matters since int
 *   is genuinely fixed-width here. Working in long long (and casting x to
 *   long long before taking its absolute value) sidesteps the classic
 *   std::abs(INT_MIN) undefined-behavior pitfall.
 *
 * Complexity:
 *   Time:  O(log10(x)) - one iteration per digit of x
 *   Space: O(1)
 *
 * Solution lives in reverse_integer.hpp so this file and
 * tests/test_reverse_integer.cpp can both use it without a duplicate main().
 */

#include <iostream>
#include "reverse_integer.hpp"

int main() {
    Solution solver;
    std::cout << solver.reverse(123) << std::endl;          // 321
    std::cout << solver.reverse(-123) << std::endl;         // -321
    std::cout << solver.reverse(120) << std::endl;            // 21
    std::cout << solver.reverse(1534236469) << std::endl;     // 0
    return 0;
}
