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
 *
 * Solution lives in longest_palindromic_substring.hpp so this file and
 * tests/test_longest_palindromic_substring.cpp can both use it without a
 * duplicate main().
 */

#include <iostream>
#include "longest_palindromic_substring.hpp"

int main() {
    Solution solver;
    std::cout << solver.longestPalindrome("babad") << std::endl;  // bab
    std::cout << solver.longestPalindrome("cbbd") << std::endl;   // bb
    return 0;
}
