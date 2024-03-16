#include <iostream>
#include "leetcode.h"

// 1: /problems/two-sum/
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

// 3: /problems/longest-substring-without-repeating-characters/
void length_of_longest_substring() {
    std::string input = "abcdefabc";
    int res = Leetcode::length_of_longest_substring(input);
    std::cout << "Length of longest substring: " << res << std::endl;
}

// 5: /problems/longest-palindromic-substring/
void longest_palindromic_substring() {
    std::string input = "babad";
    std::string res = Leetcode::longest_palindromic_substring(input);
    std::cout << "Longest palindromic substring: " << res << std::endl;
}

// 6: /problems/zigzag-conversion/
void convert() {
    std::string input = "PAYPALISHIRING";
    int num_rows = 3;
    std::string res = Leetcode::convert(input, num_rows);
    std::cout << "Zigzag conversion: " << res << std::endl;
}

// 7: /problems/reverse-integer/
void reverse() {
    int x = -2147483648;
    int res = Leetcode::reverse(x);
    std::cout << "Reverse integer: " << res << std::endl;
}

// 8: /problems/string-to-integer-atoi/
void my_atoi() {
    std::string s = " -273 degree ";
    int res = Leetcode::my_atoi(s);
    std::cout << "String to integer (atoi): " << res << std::endl;
}

// 9: /problems/palindrome-number/
void is_palindrome() {
    int x = 121;
    bool res = Leetcode::is_palindrome(x);
    std::cout << "Is palindrome: " << std::boolalpha << res << std::endl;
}

// 10: /problems/regular-expression-matching/
void is_match() {
    std::string s = "aa";
    std::string p = "a*";
    bool res = Leetcode::is_match(s, p);
    std::cout << "Regular expression matching: " << res << std::endl;
}

// 11: /problems/container-with-most-water/
void max_area() {
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = Leetcode::max_area(height);
    std::cout << "Container with most water: " << res << std::endl;
}

// 12: /problems/integer-to-roman/
void int_to_roman() {
    int num = 2024;
    std::string res = Leetcode::int_to_roman(num);
    std::cout << "Integer to roman: " << res << std::endl;
}

int main() {
    two_sum();
    length_of_longest_substring();
    longest_palindromic_substring();
    convert();
    reverse();
    my_atoi();
    is_palindrome();
    is_match();
    max_area();
    int_to_roman();
    return 0;
}
