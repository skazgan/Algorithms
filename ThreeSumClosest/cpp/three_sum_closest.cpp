/**
 * 3Sum Closest
 * -------------
 * Given an integer array nums of length n and an integer target, find
 * three integers in nums such that the sum is closest to target. Return
 * the sum of those three integers. You may assume each input has exactly
 * one solution.
 *
 * Example:
 *   Input:  nums = [-1, 2, 1, -4], target = 1
 *   Output: 2   (-1 + 2 + 1 = 2, the closest possible sum to 1)
 *
 * Approach: sort, then two pointers per anchor
 *   Sort the array first. Fix one element at index i as an "anchor,"
 *   then use two pointers -- one starting just after the anchor, one at
 *   the end of the array -- to scan for the pair that, combined with the
 *   anchor, gets the sum as close to target as possible, moving whichever
 *   pointer closes the gap, and returning immediately on an exact match.
 *
 * Complexity:
 *   Time:  O(n^2) - O(n log n) to sort, then n anchors each doing an
 *          O(n) two-pointer sweep
 *   Space: O(1) extra (not counting the space used by sort)
 *
 * Solution lives in three_sum_closest.hpp so this file and
 * tests/test_three_sum_closest.cpp can both use it without a duplicate
 * main().
 */

#include <iostream>
#include <vector>
#include "three_sum_closest.hpp"

int main() {
    Solution solver;

    std::vector<int> nums1 = {-1, 2, 1, -4};
    std::cout << solver.threeSumClosest(nums1, 1) << std::endl;  // 2

    std::vector<int> nums2 = {0, 0, 0};
    std::cout << solver.threeSumClosest(nums2, 1) << std::endl;  // 0

    return 0;
}
