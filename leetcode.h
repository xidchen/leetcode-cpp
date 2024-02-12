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

    // 9: /problems/palindrome-number/
    static bool is_palindrome(int x) {
        std::string str_x = std::to_string(x);
        return str_x == std::string(str_x.rbegin(), str_x.rend());
    }
};

#endif
