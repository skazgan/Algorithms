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
 *   past the signed 32-bit limit -- checking beforehand matters in Java,
 *   where int actually is fixed-width and would silently wrap on overflow
 *   if checked only after the fact. Working in long for the accumulator
 *   (and casting x to long before taking its absolute value) also sidesteps
 *   the classic Math.abs(Integer.MIN_VALUE) overflow pitfall.
 *
 * Complexity:
 *   Time:  O(log10(x)) - one iteration per digit of x
 *   Space: O(1)
 */

public class ReverseInteger {

    public int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;
        long xAbs = Math.abs((long) x);

        long result = 0;
        while (xAbs != 0) {
            long digit = xAbs % 10;
            xAbs /= 10;

            if (result > (Integer.MAX_VALUE - digit) / 10) {
                return 0;
            }

            result = result * 10 + digit;
        }

        result *= sign;
        return (result < Integer.MIN_VALUE || result > Integer.MAX_VALUE) ? 0 : (int) result;
    }

    public static void main(String[] args) {
        ReverseInteger solver = new ReverseInteger();
        System.out.println(solver.reverse(123));          // 321
        System.out.println(solver.reverse(-123));         // -321
        System.out.println(solver.reverse(120));            // 21
        System.out.println(solver.reverse(1534236469));     // 0
    }
}
