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
 *   anchor, gets the sum as close to target as possible:
 *     - if the current sum is too small, move the left pointer right
 *       (swap in a bigger number)
 *     - if it's too large, move the right pointer left (swap in a
 *       smaller number)
 *     - if it's an exact match, that's provably the best possible
 *       answer -- return immediately
 *   Track the closest sum found so far across every anchor and pointer
 *   position.
 *
 * Complexity:
 *   Time:  O(n^2) - O(n log n) to sort, then n anchors each doing an
 *          O(n) two-pointer sweep
 *   Space: O(1) extra (not counting the space used by sort)
 */

import java.util.Arrays;

public class ThreeSumClosest {

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int current = nums[i] + nums[left] + nums[right];

                if (current == target) {
                    return current;
                }

                if (Math.abs(current - target) < Math.abs(closest - target)) {
                    closest = current;
                }

                if (current < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }

    public static void main(String[] args) {
        ThreeSumClosest solver = new ThreeSumClosest();
        System.out.println(solver.threeSumClosest(new int[]{-1, 2, 1, -4}, 1));  // 2
        System.out.println(solver.threeSumClosest(new int[]{0, 0, 0}, 1));       // 0
    }
}
