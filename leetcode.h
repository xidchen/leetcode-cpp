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

    // 9: /problems/palindrome-number/
    static bool isPalindrome(int x) {
        std::string s0 = std::to_string(x);
        std::string s1 = s0;
        std::reverse(s0.begin(), s0.end());
        return s0 == s1;
    }
};

#endif
