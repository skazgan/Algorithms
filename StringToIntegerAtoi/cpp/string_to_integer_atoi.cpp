/**
 * String to Integer (atoi)
 * --------------------------
 * Implement the myAtoi(s) function, which converts a string to a 32-bit
 * signed integer, similar to C/C++'s atoi function.
 *
 * The algorithm:
 *   1. Skip any leading whitespace.
 *   2. Check for an optional '+' or '-' sign, and consume it if present.
 *   3. Read in digits until the next non-digit character or the end of
 *      the string, ignoring everything after. If no digits were read,
 *      the result is 0.
 *   4. Clamp the result to the signed 32-bit range [-2^31, 2^31 - 1] if
 *      it would otherwise fall outside it.
 *
 * Example:
 *   Input:  s = "42"
 *   Output: 42
 *
 *   Input:  s = "   -42"
 *   Output: -42
 *
 *   Input:  s = "4193 with words"
 *   Output: 4193
 *
 *   Input:  s = "words and 987"
 *   Output: 0
 *
 * Approach: consume, then accumulate digit by digit
 *   Find the first non-space character (skips leading whitespace, and
 *   returning 0 up front if the string is empty or all whitespace),
 *   consume an optional sign character, then walk the remaining string
 *   one character at a time, stopping at the first non-digit. Build the
 *   result as you go (num = num * 10 + digit) in a long long accumulator,
 *   checking the signed result against INT_MIN/INT_MAX after every digit
 *   so a long run of digits can never actually overflow before it's
 *   caught. Comparing the signed value (num * sign), not just the
 *   magnitude, avoids incorrectly clamping the valid boundary case
 *   "-2147483648" (exactly INT_MIN).
 *
 * Complexity:
 *   Time:  O(n) - one pass over the string
 *   Space: O(1)
 *
 * Solution lives in string_to_integer_atoi.hpp so this file and
 * tests/test_string_to_integer_atoi.cpp can both use it without a
 * duplicate main().
 */

#include <iostream>
#include "string_to_integer_atoi.hpp"

int main() {
    Solution solver;
    std::cout << solver.myAtoi("42") << std::endl;                // 42
    std::cout << solver.myAtoi("   -42") << std::endl;            // -42
    std::cout << solver.myAtoi("4193 with words") << std::endl;   // 4193
    std::cout << solver.myAtoi("words and 987") << std::endl;     // 0
    return 0;
}
