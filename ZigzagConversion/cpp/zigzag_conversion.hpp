#ifndef ZIGZAG_CONVERSION_HPP
#define ZIGZAG_CONVERSION_HPP

#include <string>
#include <vector>

class Solution {
public:
    std::string convert(const std::string& s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        int direction = -1;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = -direction;
            }
            currentRow += direction;
        }

        std::string result;
        for (const auto& row : rows) {
            result += row;
        }
        return result;
    }
};

#endif // ZIGZAG_CONVERSION_HPP
