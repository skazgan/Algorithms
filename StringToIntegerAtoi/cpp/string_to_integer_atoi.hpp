#ifndef STRING_TO_INTEGER_ATOI_HPP
#define STRING_TO_INTEGER_ATOI_HPP

#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        size_t start = s.find_first_not_of(' ');
        if (start == std::string::npos) {
            return 0;
        }
        s = s.substr(start);

        size_t i = 0;
        int sign = 1;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long long num = 0;
        while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
            num = num * 10 + (s[i] - '0');

            if (num * sign <= INT_MIN) {
                return INT_MIN;
            }
            if (num * sign >= INT_MAX) {
                return INT_MAX;
            }
            i++;
        }

        return static_cast<int>(num * sign);
    }
};

#endif // STRING_TO_INTEGER_ATOI_HPP
