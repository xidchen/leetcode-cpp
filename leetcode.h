#ifndef LEETCODE_CPP_LEETCODE_H
#define LEETCODE_CPP_LEETCODE_H

#include <string>
#include <vector>
#include <unordered_map>

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
        if (s.length() < 2 || s == std::string(s.rbegin(), s.rend())) {
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
            if (!odd.empty() && is_palindromic_string(odd)) {
                start = i - ml - 1;
                ml += 2;
                continue;
            }
            if (!even.empty() && is_palindromic_string(even)) {
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
        int y = x < 0 ? -x : x;
        std::string str_y = std::to_string(y);
        std::reverse(str_y.begin(), str_y.end());
        long long reversed = std::stoll(str_y);
        if (x < 0) reversed = -reversed;
        if (reversed < INT_MIN || reversed > INT_MAX) return 0;
        return static_cast<int>(reversed);
    }

    // 9: /problems/palindrome-number/
    static bool is_palindrome(int x) {
        std::string str_x = std::to_string(x);
        return str_x == std::string(str_x.rbegin(), str_x.rend());
    }

private:
    static bool is_palindromic_string(const std::string& s) {
        std::string::size_type left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

#endif
