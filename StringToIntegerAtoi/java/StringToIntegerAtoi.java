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
 *   Strip leading whitespace, consume an optional sign character, then
 *   walk the remaining string one character at a time. The moment a
 *   non-digit character is seen, stop. Build the result as you go
 *   (num = num * 10 + digit), accumulating in a long and checking the
 *   signed result against Integer.MIN_VALUE/MAX_VALUE after every digit
 *   -- checking every step (rather than only once at the end) matters
 *   here because int is genuinely fixed-width in Java, and a long enough
 *   run of digits could overflow even the long accumulator if left
 *   unchecked. Comparing the signed value (num * sign), not just the
 *   magnitude, also avoids incorrectly clamping the valid boundary case
 *   "-2147483648" (exactly Integer.MIN_VALUE).
 *
 * Complexity:
 *   Time:  O(n) - one pass over the string
 *   Space: O(1)
 */

public class StringToIntegerAtoi {

    public int myAtoi(String s) {
        if (s == null || s.strip().isEmpty()) {
            return 0;
        }

        s = s.strip();
        int i = 0;
        int sign = 1;

        if (s.charAt(0) == '-') {
            sign = -1;
            i = 1;
        } else if (s.charAt(0) == '+') {
            i = 1;
        }

        long num = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            num = num * 10 + (s.charAt(i) - '0');

            if (num * sign <= Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            if (num * sign >= Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            i++;
        }

        return (int) (num * sign);
    }

    public static void main(String[] args) {
        StringToIntegerAtoi solver = new StringToIntegerAtoi();
        System.out.println(solver.myAtoi("42"));                // 42
        System.out.println(solver.myAtoi("   -42"));            // -42
        System.out.println(solver.myAtoi("4193 with words"));   // 4193
        System.out.println(solver.myAtoi("words and 987"));     // 0
    }
}
