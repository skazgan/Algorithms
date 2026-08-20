import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from string_to_integer_atoi import Solution


class StringToIntegerAtoiTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def test_basic_positive(self):
        self.assertEqual(self.solver.myAtoi("42"), 42)

    def test_leading_whitespace_and_sign(self):
        self.assertEqual(self.solver.myAtoi("   -42"), -42)

    def test_stops_at_first_non_digit(self):
        self.assertEqual(self.solver.myAtoi("4193 with words"), 4193)

    def test_no_leading_digits_returns_zero(self):
        self.assertEqual(self.solver.myAtoi("words and 987"), 0)

    def test_explicit_plus_sign(self):
        self.assertEqual(self.solver.myAtoi("+1"), 1)

    def test_negative_overflow_clamped(self):
        self.assertEqual(self.solver.myAtoi("-91283472332"), -2147483648)

    def test_positive_overflow_clamped(self):
        self.assertEqual(self.solver.myAtoi("2147483648"), 2147483647)

    def test_exact_int_min_boundary(self):
        self.assertEqual(self.solver.myAtoi("-2147483648"), -2147483648)

    def test_empty_string(self):
        self.assertEqual(self.solver.myAtoi(""), 0)

    def test_whitespace_only(self):
        self.assertEqual(self.solver.myAtoi("   "), 0)


if __name__ == "__main__":
    unittest.main()
