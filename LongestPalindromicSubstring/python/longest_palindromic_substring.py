"""
Longest Palindromic Substring
------------------------------
Given a string s, return the longest substring of s that reads the same
forwards and backwards (a palindrome).

Example:
    Input:  s = "babad"
    Output: "bab"   (or "aba" -- both are valid answers)

    Input:  s = "cbbd"
    Output: "bb"

Approach: expand around center
    Every palindrome is symmetric around a center, which is either a single
    character (odd length, e.g. "aba") or the gap between two characters
    (even length, e.g. "abba"). A string of length n has 2n - 1 possible
    centers. For each one, expand outward in both directions while the
    characters match; the widest expansion found across all centers is
    the answer.

Complexity:
    Time:  O(n^2) - n centers, each expansion up to O(n)
    Space: O(1)   - no extra data structures beyond a few pointers
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        start, end = 0, 0  # best boundaries found so far

        for i in range(len(s)):
            left1, right1 = self._expand(s, i, i)        # odd-length center
            left2, right2 = self._expand(s, i, i + 1)    # even-length center

            if right1 - left1 > end - start:
                start, end = left1, right1
            if right2 - left2 > end - start:
                start, end = left2, right2

        return s[start:end + 1]

    def _expand(self, s: str, left: int, right: int):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1


if __name__ == "__main__":
    solver = Solution()
    print(solver.longestPalindrome("babad"))  # bab
    print(solver.longestPalindrome("cbbd"))   # bb
