#include <iostream>
#include <climits>
#include <string>
#include "../cpp/string_to_integer_atoi.hpp"

static int failures = 0;

static void check(const std::string& name, const std::string& input, int expected) {
    Solution solver;
    int actual = solver.myAtoi(input);
    if (actual != expected) {
        std::cout << "FAILED: " << name << " expected=" << expected << " actual=" << actual << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    check("basic_positive", "42", 42);
    check("leading_whitespace_and_sign", "   -42", -42);
    check("stops_at_first_non_digit", "4193 with words", 4193);
    check("no_leading_digits_returns_zero", "words and 987", 0);
    check("explicit_plus_sign", "+1", 1);
    check("negative_overflow_clamped", "-91283472332", INT_MIN);
    check("positive_overflow_clamped", "2147483648", INT_MAX);
    check("exact_int_min_boundary", "-2147483648", INT_MIN);
    check("empty_string", "", 0);
    check("whitespace_only", "   ", 0);

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
