/**
 * Longest Palindromic Substring
 * ------------------------------
 * Given a string s, return the longest substring of s that reads the same
 * forwards and backwards (a palindrome).
 *
 * Example:
 *   Input:  s = "babad"
 *   Output: "bab"   (or "aba" -- both are valid answers)
 *
 *   Input:  s = "cbbd"
 *   Output: "bb"
 *
 * Approach: expand around center
 *   Every palindrome is symmetric around a center, which is either a single
 *   character (odd length, e.g. "aba") or the gap between two characters
 *   (even length, e.g. "abba"). A string of length n has 2n - 1 possible
 *   centers. For each one, expand outward in both directions while the
 *   characters match; the widest expansion found across all centers is
 *   the answer.
 *
 * Complexity:
 *   Time:  O(n^2) - n centers, each expansion up to O(n)
 *   Space: O(1)   - no extra data structures beyond a few pointers
 */

public class LongestPalindromicSubstring {

    public String longestPalindrome(String s) {
        if (s == null || s.isEmpty()) {
            return "";
        }

        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            int[] odd = expand(s, i, i);
            int[] even = expand(s, i, i + 1);

            if (odd[1] - odd[0] > end - start) {
                start = odd[0];
                end = odd[1];
            }
            if (even[1] - even[0] > end - start) {
                start = even[0];
                end = even[1];
            }
        }

        return s.substring(start, end + 1);
    }

    private int[] expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return new int[]{left + 1, right - 1};
    }

    public static void main(String[] args) {
        LongestPalindromicSubstring solver = new LongestPalindromicSubstring();
        System.out.println(solver.longestPalindrome("babad"));  // bab
        System.out.println(solver.longestPalindrome("cbbd"));   // bb
    }
}
