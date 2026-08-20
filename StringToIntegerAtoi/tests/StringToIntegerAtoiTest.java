/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/StringToIntegerAtoi.java and run the main method.
 */
public class StringToIntegerAtoiTest {

    private static int failures = 0;

    public static void main(String[] args) {
        check("basic_positive", "42", 42);
        check("leading_whitespace_and_sign", "   -42", -42);
        check("stops_at_first_non_digit", "4193 with words", 4193);
        check("no_leading_digits_returns_zero", "words and 987", 0);
        check("explicit_plus_sign", "+1", 1);
        check("negative_overflow_clamped", "-91283472332", Integer.MIN_VALUE);
        check("positive_overflow_clamped", "2147483648", Integer.MAX_VALUE);
        check("exact_int_min_boundary", "-2147483648", Integer.MIN_VALUE);
        check("empty_string", "", 0);
        check("whitespace_only", "   ", 0);

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void check(String name, String input, int expected) {
        StringToIntegerAtoi solver = new StringToIntegerAtoi();
        int actual = solver.myAtoi(input);
        if (actual != expected) {
            System.out.println("FAILED: " + name + " expected=" + expected + " actual=" + actual);
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }
}
