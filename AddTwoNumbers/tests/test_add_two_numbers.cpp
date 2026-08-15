#include <iostream>
#include <string>
#include <vector>
#include "../cpp/add_two_numbers.hpp"

static int failures = 0;

static void check(const std::string& name,
                   const std::vector<int>& l1Digits,
                   const std::vector<int>& l2Digits,
                   const std::vector<int>& expected) {
    Solution solver;
    ListNode* l1 = buildList(l1Digits);
    ListNode* l2 = buildList(l2Digits);
    ListNode* result = solver.addTwoNumbers(l1, l2);
    std::vector<int> actual = listToVector(result);

    if (actual != expected) {
        std::cout << "FAILED: " << name << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    check("basic_example", {2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    check("carry_creates_new_digit", {9, 9}, {1}, {0, 0, 1});
    check("both_zero", {0}, {0}, {0});
    check("different_lengths", {9, 9, 9}, {1}, {0, 0, 0, 1});
    check("single_digits_no_carry", {2}, {3}, {5});
    check("carry_propagates_through_shorter_list", {1}, {9, 9}, {0, 0, 1});
    check("large_numbers",
          {9, 9, 9, 9, 9, 9, 8},
          {9, 9, 9, 9, 9, 9, 9},
          {8, 9, 9, 9, 9, 9, 8, 1});

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
