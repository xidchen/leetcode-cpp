#ifndef LEETCODE_CPP_LEETCODE_H
#define LEETCODE_CPP_LEETCODE_H

#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Leetcode {
public:
    Leetcode() = default;

    virtual ~Leetcode() = default;

    // 1: /problems/two-sum/
    static std::vector<int> two_sum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); ++i) {
            if (dic.find(nums[i]) != dic.end()) {
                return {dic[nums[i]], i};
            }
            dic[target - nums[i]] = i;
        }
        return {};
    }

    // 3: /problems/longest-substring-without-repeating-characters/
    static int length_of_longest_substring(const std::string& s) {
        std::unordered_map<char, int> last_seen;
        int start = 0, longest = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (last_seen.find(c) != last_seen.end() &&
                last_seen[c] >= start) {
                start = last_seen[c] + 1;
            } else {
                longest = std::max(longest, i - start + 1);
            }
            last_seen[c] = i;
        }
        return longest;
    }

    // 5: /problems/longest-palindromic-substring/
    static std::string longest_palindromic_substring(const std::string& s) {
        if (s.length() < 2 || s == std::string(
                s.rbegin(), s.rend())) {
            return s;
        }
        int start = -1, ml = 0;
        for (int i = 0; i < s.length(); i++) {
            std::string odd, even;
            if (i - ml - 1 >= 0) {
                odd = s.substr(i - ml - 1, ml + 2);
            }
            if (i - ml >= 0) {
                even = s.substr(i - ml, ml + 1);
            }
            if (!odd.empty() && odd == std::string(
                    odd.rbegin(), odd.rend())) {
                start = i - ml - 1;
                ml += 2;
                continue;
            }
            if (!even.empty() && even == std::string(
                    even.rbegin(), even.rend())) {
                start = i - ml;
                ml += 1;
            }
        }
        return s.substr(start, ml);
    }

    // 6: /problems/zigzag-conversion/
    static std::string convert(const std::string& s, int num_rows) {
        if (num_rows == 1 || s.length() < num_rows) {
            return s;
        }
        std::vector<std::string> zigzag(num_rows, "");
        int row = 0;
        int step = 1;
        for (char c : s) {
            zigzag[row] += c;
            if (row == 0) {
                step = 1;
            }
            if (row == num_rows - 1) {
                step = -1;
            }
            row += step;
        }
        std::string res;
        for (const std::string& str : zigzag) {
            res += str;
        }
        return res;
    }

    // 7: /problems/reverse-integer/
    static int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool negative = x < 0;
        x = abs(x);
        long long y = 0;
        while (x != 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (y > INT_MAX) return 0;
        return negative ? static_cast<int>(-y) : static_cast<int>(y);
    }

    // 8: /problems/string-to-integer-atoi/
    static int my_atoi(std::string& s) {
        s.erase(0, s.find_first_not_of(' '));
        if (s.empty()) return 0;
        int i = 0, sign = 1;
        if (s[i] == '+' || s[i] == '-') sign = (s[i++] == '+') ? 1: -1;
        long long res = 0;
        while (i < s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i++] - '0');
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }
        return static_cast<int>(res * sign);
    }

    // 9: /problems/palindrome-number/
    static bool is_palindrome(int x) {
        std::string s = std::to_string(x);
        return s == std::string(s.rbegin(), s.rend());
    }

    // 10: /problems/regular-expression-matching/
    static bool is_match(const std::string& s, const std::string& p) {
        std::vector<std::vector<bool>> dp(
                s.length() + 1,
                std::vector<bool>(p.length() + 1, false));
        dp[s.length()][p.length()] = true;
        for (size_t i = s.length(); i != static_cast<size_t>(-1); --i) {
            for (size_t j = p.length() - 1; j != static_cast<size_t>(-1); --j) {
                bool first_match = i < s.length() && (p[j] == s[i] || p[j] == '.');
                if (j + 1 < p.length() && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }

    // 11: /problems/container-with-most-water/
    static int max_area(const std::vector<int>& height) {
        int max_area = 0;
        size_t i = 0, j = height.size() - 1;
        while (i < j) {
            max_area = std::max(
                    max_area,
                    std::min(static_cast<int>(height[i]), static_cast<int>(height[j])) *
                    static_cast<int>(j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return max_area;
    }

    // 12: /problems/integer-to-roman/
    static std::string int_to_roman(int num) {
        std::vector<std::pair<int, std::string>> mapping {
            {1000, "M"}, {900, "CM"},
            {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"},
            {1, "I"},
        };
        std::string romans;
        for (const auto& pair : mapping) {
            while (pair.first <= num) {
                num -= pair.first;
                romans += pair.second;
            }
        }
        return romans;
    }

    // 13: /problems/roman-to-integer/
    static int roman_to_int(const std::string& s) {
        std::unordered_map<char, int> d = {
            {'I', 1}, {'V', 5},
            {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500},
            {'M', 1000},
        };
        int integer = 0, prev_int = 0;
        for (std::string::size_type i = s.size(); i-- > 0;) {
            char roman = s[i];
            if (d[roman] >= prev_int) {
                prev_int = d[roman];
                integer += d[roman];
            } else {
                integer -= d[roman];
            }
        }
        return integer;
    }

    // 14: /problems/longest-common-prefix/
    static std::string longest_common_prefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        std::sort(strs.begin(), strs.end());
        std::string result;
        for (size_t i = 0; i < strs[0].size() && i < strs.back().size(); i++) {
            if (strs[0][i] == strs.back()[i]) result.push_back(strs[0][i]);
            else break;
        }
        return result;
    }

    // 15: /problems/3sum
    static std::vector<std::vector<int>> three_sum(std::vector<int>& nums) {
        std::unordered_map<int, int> dic;
        std::vector<std::vector<int>> res;
        for (int n : nums) dic[n]++;
        std::vector<int> sorted_nums;
        sorted_nums.reserve(dic.size());
        for (auto& pair : dic) {
            sorted_nums.push_back(pair.first);
        }
        std::sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < sorted_nums.size(); ++i) {
            int x = sorted_nums[i];
            if (x == 0 && dic[x] > 2) res.push_back({0, 0, 0});
            else if (x != 0 && dic[x] > 1 && dic.count(-2 * x) > 0) {
                res.push_back({x, x, -2 * x});
            }
            if (x < 0) {
                auto left = std::lower_bound(
                        sorted_nums.begin() + i + 1,
                        sorted_nums.end(),
                        -x - *sorted_nums.rbegin());
                auto right = std::upper_bound(
                        sorted_nums.begin() + i + 1,
                        sorted_nums.end(),
                        x / -2);
                for (auto it = left; it != right; ++it) {
                    int y = *it;
                    int z = -x - y;
                    if (dic.count(z) > 0 && z != y) {
                        res.push_back({x, y, z});
                    }
                }
            }
        }
        return res;
    }

};

#endif
