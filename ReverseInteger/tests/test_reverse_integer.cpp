#include <iostream>
#include <climits>
#include <string>
#include "../cpp/reverse_integer.hpp"

static int failures = 0;

static void check(const std::string& name, int input, int expected) {
    Solution solver;
    int actual = solver.reverse(input);
    if (actual != expected) {
        std::cout << "FAILED: " << name << " expected=" << expected << " actual=" << actual << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    check("positive_no_overflow", 123, 321);
    check("negative_no_overflow", -123, -321);
    check("trailing_zero", 120, 21);
    check("zero", 0, 0);
    check("positive_overflow", 1534236469, 0);
    check("negative_overflow_int_min", INT_MIN, 0);
    check("large_value_no_overflow", 1000000001, 1000000001);

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
