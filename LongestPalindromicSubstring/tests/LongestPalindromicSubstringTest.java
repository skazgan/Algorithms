/**
 * Plain-assertion test runner (no JUnit dependency required).
 * Compile together with java/LongestPalindromicSubstring.java and run the main method.
 */
public class LongestPalindromicSubstringTest {

    private static int failures = 0;

    public static void main(String[] args) {
        checkExact("odd_length_palindrome", "babad", "bab");
        checkExact("even_length_palindrome", "cbbd", "bb");
        checkExact("single_character", "a", "a");
        checkExact("whole_string_is_palindrome", "racecar", "racecar");
        checkLength("no_repeated_characters", "abc", 1);
        checkExact("empty_string", "", "");
        checkExact("all_same_characters", "aaaa", "aaaa");

        if (failures > 0) {
            System.out.println(failures + " test(s) failed.");
            System.exit(1);
        }
        System.out.println("All tests passed.");
    }

    private static void checkExact(String name, String input, String expected) {
        LongestPalindromicSubstring solver = new LongestPalindromicSubstring();
        String actual = solver.longestPalindrome(input);
        if (!actual.equals(expected)) {
            System.out.println("FAILED: " + name + " expected=\"" + expected + "\" actual=\"" + actual + "\"");
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }

    private static void checkLength(String name, String input, int expectedLength) {
        LongestPalindromicSubstring solver = new LongestPalindromicSubstring();
        String actual = solver.longestPalindrome(input);
        if (actual.length() != expectedLength) {
            System.out.println("FAILED: " + name + " expectedLength=" + expectedLength + " actual=\"" + actual + "\"");
            failures++;
        } else {
            System.out.println("PASSED: " + name);
        }
    }
}
