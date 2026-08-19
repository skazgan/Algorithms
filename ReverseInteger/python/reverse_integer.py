"""
Reverse Integer
----------------
Given a signed 32-bit integer x, return x with its digits reversed. If
reversing x causes the value to go outside the signed 32-bit integer range
[-2^31, 2^31 - 1], return 0 instead.

Example:
    Input:  x = 123
    Output: 321

    Input:  x = -123
    Output: -321

    Input:  x = 120
    Output: 21

    Input:  x = 1534236469
    Output: 0   (reversed digits would be 9646324351, which overflows)

Approach: digit-by-digit extraction, with overflow checked before it happens
    Strip the sign, then repeatedly peel off the last digit of x (x % 10)
    and build up the reversed number one digit at a time (result * 10 +
    digit), the same way you'd read digits off a number from the ones
    place outward. Before every multiply, check whether it would push the
    result past the signed 32-bit limit -- checking beforehand (rather
    than computing the oversized value and checking after) matters because
    in a fixed-width integer type, the overflow would already have
    happened by the time you got around to checking it.

Complexity:
    Time:  O(log10(x)) - one iteration per digit of x
    Space: O(1)
"""


class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1

        sign = -1 if x < 0 else 1
        x = abs(x)

        result = 0
        while x != 0:
            digit = x % 10
            x //= 10

            if result > (INT_MAX - digit) // 10:
                return 0

            result = result * 10 + digit

        result *= sign
        return result if INT_MIN <= result <= INT_MAX else 0


if __name__ == "__main__":
    solver = Solution()
    print(solver.reverse(123))          # 321
    print(solver.reverse(-123))         # -321
    print(solver.reverse(120))          # 21
    print(solver.reverse(1534236469))   # 0
