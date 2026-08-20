import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))

from three_sum_closest import Solution


class ThreeSumClosestTest(unittest.TestCase):
    def setUp(self):
        self.solver = Solution()

    def test_classic_example(self):
        self.assertEqual(self.solver.threeSumClosest([-1, 2, 1, -4], 1), 2)

    def test_exact_match_triggers_early_return(self):
        self.assertEqual(self.solver.threeSumClosest([1, 1, 1, 0], 2), 2)

    def test_all_zeros(self):
        self.assertEqual(self.solver.threeSumClosest([0, 0, 0], 1), 0)

    def test_exactly_three_elements(self):
        self.assertEqual(self.solver.threeSumClosest([1, 1, 1], 0), 3)

    def test_negative_numbers_exact_match(self):
        self.assertEqual(self.solver.threeSumClosest([1, 1, -1, -1, 3], -1), -1)

    def test_target_far_beyond_reach(self):
        self.assertEqual(self.solver.threeSumClosest([1, 1, 1, 1], 100), 3)

    def test_duplicates_with_exact_zero_sum(self):
        self.assertEqual(self.solver.threeSumClosest([-4, -1, -1, 0, 1, 2], 0), 0)

    def test_larger_array_no_exact_match(self):
        self.assertEqual(self.solver.threeSumClosest([1, 2, 4, 8, 16, 32, 64, 128], 80), 81)


if __name__ == "__main__":
    unittest.main()
