import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from longest_palindromic_substring import Solution


class LongestPalindromicSubstringTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def test_odd_length_palindrome(self):
        self.assertEqual(self.solver.longestPalindrome("babad"), "bab")

    def test_even_length_palindrome(self):
        self.assertEqual(self.solver.longestPalindrome("cbbd"), "bb")

    def test_single_character(self):
        self.assertEqual(self.solver.longestPalindrome("a"), "a")

    def test_whole_string_is_palindrome(self):
        self.assertEqual(self.solver.longestPalindrome("racecar"), "racecar")

    def test_no_repeated_characters(self):
        result = self.solver.longestPalindrome("abc")
        self.assertEqual(len(result), 1)

    def test_empty_string(self):
        self.assertEqual(self.solver.longestPalindrome(""), "")

    def test_all_same_characters(self):
        self.assertEqual(self.solver.longestPalindrome("aaaa"), "aaaa")


if __name__ == "__main__":
    unittest.main()
