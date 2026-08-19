/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/ReverseInteger.java and run the main method.
 */
public class ReverseIntegerTest {

    private static int failures = 0;

    public static void main(String[] args) {
        check("positive_no_overflow", 123, 321);
        check("negative_no_overflow", -123, -321);
        check("trailing_zero", 120, 21);
        check("zero", 0, 0);
        check("positive_overflow", 1534236469, 0);
        check("negative_overflow_int_min", Integer.MIN_VALUE, 0);
        check("large_value_no_overflow", 1000000001, 1000000001);

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void check(String name, int input, int expected) {
        ReverseInteger solver = new ReverseInteger();
        int actual = solver.reverse(input);
        if (actual != expected) {
            System.out.println("FAILED: " + name + " expected=" + expected + " actual=" + actual);
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }
}
