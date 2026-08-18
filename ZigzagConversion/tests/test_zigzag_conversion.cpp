#include <iostream>
#include <string>
#include "../cpp/zigzag_conversion.hpp"

static int failures = 0;

static void check(const std::string& name, const std::string& input, int numRows, const std::string& expected) {
    Solution solver;
    std::string actual = solver.convert(input, numRows);
    if (actual != expected) {
        std::cout << "FAILED: " << name << " expected=\"" << expected << "\" actual=\"" << actual << "\"" << std::endl;
        failures++;
    } else {
        std::cout << "PASSED: " << name << std::endl;
    }
}

int main() {
    check("classic_three_rows", "PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    check("four_rows", "PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    check("single_row_no_zigzag", "A", 1, "A");
    check("single_row_longer_string", "HELLO", 1, "HELLO");
    check("num_rows_at_least_length", "AB", 5, "AB");
    check("two_rows_interleave", "ABCDE", 2, "ACEBD");
    check("exact_length_rows", "ABCD", 4, "ABCD");

    if (failures > 0) {
        std::cout << failures << " test(s) failed." << std::endl;
        return 1;
    }
    std::cout << "All tests passed." << std::endl;
    return 0;
}
