#ifndef LONGEST_PALINDROMIC_SUBSTRING_HPP
#define LONGEST_PALINDROMIC_SUBSTRING_HPP

#include <string>
#include <utility>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        if (s.empty()) return "";

        int start = 0, end = 0;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            auto odd = expand(s, i, i);
            auto even = expand(s, i, i + 1);

            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }
            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    std::pair<int, int> expand(const std::string& s, int left, int right) {
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};

#endif // LONGEST_PALINDROMIC_SUBSTRING_HPP
