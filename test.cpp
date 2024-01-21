#include <iostream>
#include "leetcode.h"

void two_sum() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = Leetcode::two_sum(nums, target);
    for (int index : res) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}

void length_of_longest_substring() {
    std::string input = "abcdefabc";
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
    two_sum();
    length_of_longest_substring();
    isPalindrom();
    return 0;
}
