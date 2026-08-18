/**
 * ZigZag Conversion
 * ------------------
 * Given a string s and an integer numRows, write the string in a zigzag
 * pattern across numRows rows (down one column, then diagonally up to the
 * next column, repeating), then read the result row by row and concatenate.
 *
 * Example:
 *   Input:  s = "PAYPALISHIRING", numRows = 3
 *   Output: "PAHNAPLSIIGYIR"
 *
 *   Input:  s = "PAYPALISHIRING", numRows = 4
 *   Output: "PINALSIGYAHRPI"
 *
 *   Input:  s = "A", numRows = 1
 *   Output: "A"
 *
 * Approach: simulate the bounce
 *   Track a currentRow pointer and a direction (+1 or -1). Walk the string
 *   once, appending each character to the row it currently sits on. Every
 *   time the pointer touches the top row (0) or the bottom row
 *   (numRows - 1), flip the direction -- like a ball bouncing between two
 *   walls. Join the row buckets together at the end.
 *
 * Complexity:
 *   Time:  O(n) - one pass over the string
 *   Space: O(n) - the row buckets together hold every character once
 *
 * Solution lives in zigzag_conversion.hpp so this file and
 * tests/test_zigzag_conversion.cpp can both use it without a duplicate main().
 */

#include <iostream>
#include "zigzag_conversion.hpp"

int main() {
    Solution solver;
    std::cout << solver.convert("PAYPALISHIRING", 3) << std::endl;  // PAHNAPLSIIGYIR
    std::cout << solver.convert("PAYPALISHIRING", 4) << std::endl;  // PINALSIGYAHRPI
    std::cout << solver.convert("A", 1) << std::endl;                // A
    return 0;
}
