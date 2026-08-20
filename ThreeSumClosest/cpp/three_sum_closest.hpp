#ifndef THREE_SUM_CLOSEST_HPP
#define THREE_SUM_CLOSEST_HPP

#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (size_t i = 0; i < nums.size() - 2; i++) {
            size_t left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int current = nums[i] + nums[left] + nums[right];

                if (current == target) {
                    return current;
                }

                if (std::abs(current - target) < std::abs(closest - target)) {
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
};

#endif // THREE_SUM_CLOSEST_HPP
