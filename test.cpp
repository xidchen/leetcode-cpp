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

void isPalindrom() {
    auto *lc = new Leetcode();
    int x = 121;
    bool res = Leetcode::isPalindrome(x);
    std::cout << res << std::endl;
    delete lc;
}

int main() {
    twoSum();
    isPalindrom();
    return 0;
}
