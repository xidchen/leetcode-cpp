#include <iostream>
#include "leetcode.h"

void two_sum() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = Leetcode::two_sum(nums, target);
    std::cout << "Two sum: ";
    for (int index : res) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}

void length_of_longest_substring() {
    std::string input = "abcdefabc";
    int res = Leetcode::length_of_longest_substring(input);
    std::cout << "Length of longest substring: " << res << std::endl;
}

void convert() {
    std::string input = "PAYPALISHIRING";
    int num_rows = 3;
    std::string res = Leetcode::convert(input, num_rows);
    std::cout << "Zigzag conversion: " << res << std::endl;
}

void is_palindrom() {
    int x = 121;
    bool res = Leetcode::is_palindrome(x);
    std::cout << "Is palindrome: " << std::boolalpha << res << std::endl;
}

int main() {
    two_sum();
    length_of_longest_substring();
    convert();
    is_palindrom();
    return 0;
}
