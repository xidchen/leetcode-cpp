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
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            if (dic.find(target - nums[i]) != dic.end()) {
                return {dic[target - nums[i]], i};
            }
            dic[nums[i]] = i;
        }
        return {};
    }

    // 3: /problems/longest-substring-without-repeating-characters/
    static int length_of_longest_substring(const std::string& s) {
        std::string ss;
        int ll = 0, cl = 0;
        for (char x : s) {
            auto it = std::find(ss.begin(), ss.end(), x);
            if (it != ss.end()) {
                ss = std::string(it + 1, ss.end()) + x;
                cl = static_cast<int>(ss.length());
            } else {
                ss += x;
                cl++;
                ll = (cl > ll) ? cl : ll;
            }
        }
        return ll;
    }

    // 9: /problems/palindrome-number/
    static bool isPalindrome(int x) {
        std::string s0 = std::to_string(x);
        std::string s1 = s0;
        std::reverse(s0.begin(), s0.end());
        return s0 == s1;
    }
};

#endif
