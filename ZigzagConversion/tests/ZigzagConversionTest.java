/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/ZigzagConversion.java and run the main method.
 */
public class ZigzagConversionTest {

    private static int failures = 0;

    public static void main(String[] args) {
        check("classic_three_rows", "PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
        check("four_rows", "PAYPALISHIRING", 4, "PINALSIGYAHRPI");
        check("single_row_no_zigzag", "A", 1, "A");
        check("single_row_longer_string", "HELLO", 1, "HELLO");
        check("num_rows_at_least_length", "AB", 5, "AB");
        check("two_rows_interleave", "ABCDE", 2, "ACEBD");
        check("exact_length_rows", "ABCD", 4, "ABCD");

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void check(String name, String input, int numRows, String expected) {
        ZigzagConversion solver = new ZigzagConversion();
        String actual = solver.convert(input, numRows);
        if (!actual.equals(expected)) {
            System.out.println("FAILED: " + name + " expected=\"" + expected + "\" actual=\"" + actual + "\"");
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }
}
