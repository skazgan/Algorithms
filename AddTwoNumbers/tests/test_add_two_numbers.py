import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from add_two_numbers import Solution, build_list


class AddTwoNumbersTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def add(self, digits1, digits2):
        l1 = build_list(digits1)
        l2 = build_list(digits2)
        result = self.solver.addTwoNumbers(l1, l2)
        out = []
        while result:
            out.append(result.val)
            result = result.next
        return out

    def test_basic_example(self):
        # 342 + 465 = 807
        self.assertEqual(self.add([2, 4, 3], [5, 6, 4]), [7, 0, 8])

    def test_carry_creates_new_digit(self):
        # 99 + 1 = 100
        self.assertEqual(self.add([9, 9], [1]), [0, 0, 1])

    def test_both_zero(self):
        # 0 + 0 = 0
        self.assertEqual(self.add([0], [0]), [0])

    def test_different_lengths(self):
        # 999 + 1 = 1000
        self.assertEqual(self.add([9, 9, 9], [1]), [0, 0, 0, 1])

    def test_single_digits_no_carry(self):
        # 2 + 3 = 5
        self.assertEqual(self.add([2], [3]), [5])

    def test_carry_propagates_through_shorter_list(self):
        # 1 + 99 = 100 (carry must ripple past where l1 runs out)
        self.assertEqual(self.add([1], [9, 9]), [0, 0, 1])

    def test_large_numbers(self):
        # 8999999 + 9999999 = 18999998
        self.assertEqual(
            self.add([9, 9, 9, 9, 9, 9, 8], [9, 9, 9, 9, 9, 9, 9]),
            [8, 9, 9, 9, 9, 9, 8, 1],
        )


if __name__ == "__main__":
    unittest.main()
