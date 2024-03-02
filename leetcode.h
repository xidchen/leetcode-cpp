#ifndef LEETCODE_CPP_LEETCODE_H
#define LEETCODE_CPP_LEETCODE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
        std::string str_x = std::to_string(x);
        return str_x == std::string(str_x.rbegin(), str_x.rend());
    }

};

#endif
