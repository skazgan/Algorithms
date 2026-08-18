import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from zigzag_conversion import Solution


class ZigzagConversionTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def test_classic_three_rows(self):
        self.assertEqual(self.solver.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR")

    def test_four_rows(self):
        self.assertEqual(self.solver.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI")

    def test_single_row_no_zigzag(self):
        self.assertEqual(self.solver.convert("A", 1), "A")

    def test_single_row_longer_string(self):
        self.assertEqual(self.solver.convert("HELLO", 1), "HELLO")

    def test_num_rows_at_least_length(self):
        self.assertEqual(self.solver.convert("AB", 5), "AB")

    def test_two_rows_interleave(self):
        self.assertEqual(self.solver.convert("ABCDE", 2), "ACEBD")

    def test_exact_length_rows(self):
        self.assertEqual(self.solver.convert("ABCD", 4), "ABCD")


if __name__ == "__main__":
    unittest.main()
