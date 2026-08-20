"""
3Sum Closest
-------------
Given an integer array nums of length n and an integer target, find three
integers in nums such that the sum is closest to target. Return the sum
of those three integers. You may assume each input has exactly one
solution.

Example:
    Input:  nums = [-1, 2, 1, -4], target = 1
    Output: 2   (-1 + 2 + 1 = 2, the closest possible sum to 1)

Approach: sort, then two pointers per anchor
    Sort the array first. Fix one element at index i as an "anchor,"
    then use two pointers -- one starting just after the anchor, one at
    the end of the array -- to scan for the pair that, combined with the
    anchor, gets the sum as close to target as possible:
      - if the current sum is too small, move the left pointer right
        (swap in a bigger number)
      - if it's too large, move the right pointer left (swap in a
        smaller number)
      - if it's an exact match, that's provably the best possible
        answer -- return immediately, no further searching can improve on it
    Track the closest sum found so far across every anchor and pointer
    position. Because the array is sorted, this explores every relevant
    pair for each anchor in a single sweep, rather than checking every
    possible triplet individually.

Complexity:
    Time:  O(n^2) - O(n log n) to sort, then n anchors each doing an
           O(n) two-pointer sweep
    Space: O(1) extra (not counting the space used by sort)
"""

from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            while left < right:
                current = nums[i] + nums[left] + nums[right]

                if current == target:
                    return current

                if abs(current - target) < abs(closest - target):
                    closest = current

                if current < target:
                    left += 1
                else:
                    right -= 1

        return closest


if __name__ == "__main__":
    solver = Solution()
    print(solver.threeSumClosest([-1, 2, 1, -4], 1))  # 2
    print(solver.threeSumClosest([0, 0, 0], 1))       # 0
