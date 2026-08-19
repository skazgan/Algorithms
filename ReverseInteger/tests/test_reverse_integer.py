import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from reverse_integer import Solution


class ReverseIntegerTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def test_positive_no_overflow(self):
        self.assertEqual(self.solver.reverse(123), 321)

    def test_negative_no_overflow(self):
        self.assertEqual(self.solver.reverse(-123), -321)

    def test_trailing_zero(self):
        self.assertEqual(self.solver.reverse(120), 21)

    def test_zero(self):
        self.assertEqual(self.solver.reverse(0), 0)

    def test_positive_overflow(self):
        self.assertEqual(self.solver.reverse(1534236469), 0)

    def test_negative_overflow_int_min(self):
        self.assertEqual(self.solver.reverse(-2147483648), 0)

    def test_large_value_no_overflow(self):
        self.assertEqual(self.solver.reverse(1000000001), 1000000001)


if __name__ == "__main__":
    unittest.main()
