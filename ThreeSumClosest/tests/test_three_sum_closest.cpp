#include <iostream>
#include <vector>
#include <string>
#include "../cpp/three_sum_closest.hpp"

static int failures = 0;

static void check(const std::string& name, std::vector<int> nums, int target, int expected) {
    Solution solver;
    int actual = solver.threeSumClosest(nums, target);
    if (actual != expected) {
        std::cout << "FAILED: " << name << " expected=" << expected << " actual=" << actual << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    check("classic_example", {-1, 2, 1, -4}, 1, 2);
    check("exact_match_triggers_early_return", {1, 1, 1, 0}, 2, 2);
    check("all_zeros", {0, 0, 0}, 1, 0);
    check("exactly_three_elements", {1, 1, 1}, 0, 3);
    check("negative_numbers_exact_match", {1, 1, -1, -1, 3}, -1, -1);
    check("target_far_beyond_reach", {1, 1, 1, 1}, 100, 3);
    check("duplicates_with_exact_zero_sum", {-4, -1, -1, 0, 1, 2}, 0, 0);
    check("larger_array_no_exact_match", {1, 2, 4, 8, 16, 32, 64, 128}, 80, 81);

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
