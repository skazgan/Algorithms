#include <iostream>
#include <string>
#include "../cpp/longest_palindromic_substring.hpp"

static int failures = 0;

static void checkExact(const std::string& name, const std::string& input, const std::string& expected) {
    Solution solver;
    std::string actual = solver.longestPalindrome(input);
    if (actual != expected) {
        std::cout << "FAILED: " << name << " expected=\"" << expected << "\" actual=\"" << actual << "\"" << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

static void checkLength(const std::string& name, const std::string& input, size_t expectedLength) {
    Solution solver;
    std::string actual = solver.longestPalindrome(input);
    if (actual.size() != expectedLength) {
        std::cout << "FAILED: " << name << " expectedLength=" << expectedLength << " actual=\"" << actual << "\"" << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    checkExact("odd_length_palindrome", "babad", "bab");
    checkExact("even_length_palindrome", "cbbd", "bb");
    checkExact("single_character", "a", "a");
    checkExact("whole_string_is_palindrome", "racecar", "racecar");
    checkLength("no_repeated_characters", "abc", 1);
    checkExact("empty_string", "", "");
    checkExact("all_same_characters", "aaaa", "aaaa");

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
