#include <iostream>
#include "leetcode.h"

void twoSum() {
    auto *lc = new Leetcode();
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = Leetcode::twoSum(nums, target);
    bool flag = true;
    std::cout << "[";
    for (auto i: res) {
        if (flag) { flag = false; } else { std::cout << ", "; }
        std::cout << i;
    }
    std::cout << "]" << std::endl;
    delete lc;
}

void length_of_longest_substring() {
    std::string input = "your_input_string_here";
    int res = Leetcode::length_of_longest_substring(input);
    std::cout << res << std::endl;
}

void isPalindrom() {
    auto *lc = new Leetcode();
    int x = 121;
    bool res = Leetcode::isPalindrome(x);
    std::cout << res << std::endl;
    delete lc;
}

int main() {
    twoSum();
    length_of_longest_substring();
    isPalindrom();
    return 0;
}
