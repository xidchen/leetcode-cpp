#include <iostream>
#include "leetcode.h"

// 1: /problems/two-sum/
void two_sum() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = Leetcode::two_sum(nums, target);
    std::cout << "Two sum: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 2: /problems/add-two-numbers/
void add_two_numbers() {
    std::shared_ptr l1 = Leetcode::vector_to_linked_list({9,9,9,9,9,9,9});
    std::shared_ptr l2 = Leetcode::vector_to_linked_list({9,9,9,9});
    std::shared_ptr result = Leetcode::add_two_numbers(l1, l2);
    std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Add two numbers: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
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

// 13: /problems/roman-to-integer/
void roman_to_int() {
    std::string s = "MMXXIV";
    int res = Leetcode::roman_to_int(s);
    std::cout << "Roman to integer: " << res << std::endl;
}

// 14: /problems/longest-common-prefix/
void longest_common_prefix() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string res = Leetcode::longest_common_prefix(strs);
    std::cout << "Longest common integer: " << res << std::endl;
}

// 15: /problems/3sum
void three_sum() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = Leetcode::three_sum(nums);
    std::cout << "Three sum: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j];
            if (j < res[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 16: /problems/3sum-closest/
void three_sum_closest() {
    std::vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target = -2;
    int res = Leetcode::three_sum_closest(nums, target);
    std::cout << "Three sum closest: " << res << std::endl;
}

// 17: /problems/letter-combinations-of-a-phone-number/
void letter_combinations() {
    std::string digits = "38";
    std::vector<std::string> res = Leetcode::letter_combinations(digits);
    std::cout << "Letter combinations: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 18: /problems/4sum/
void four_sum() {
    std::vector<int> nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    int target = 1000000000;
    std::vector<std::vector<int>> res = Leetcode::four_sum(nums, target);
    std::cout << "Three sum: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j];
            if (j < res[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 19: /problems/remove-nth-node-from-end-of-list/
void remove_nth_from_end() {
    std::shared_ptr head = Leetcode::vector_to_linked_list({1,2,3,4,5});
    int n = 2;
    std::shared_ptr result = Leetcode::remove_nth_from_end(head, n);
    std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Remove nth node from end of list: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 20: /problems/valid-parentheses/
void is_valid() {
    std::string s = "()[]{}";
    bool res = Leetcode::is_valid(s);
    std::cout << "Valid parentheses: " << std::boolalpha << res << std::endl;
}

// 21: /problems/merge-two-sorted-lists/
void merge_two_lists() {
    std::shared_ptr l1 = Leetcode::vector_to_linked_list({1, 2, 4});
    std::shared_ptr l2 = Leetcode::vector_to_linked_list({1, 3, 4});
    std::shared_ptr result = Leetcode::merge_two_lists(l1, l2);
    std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Merge two sorted lists: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 22: /problems/generate-parentheses/
void generate_parenthesis() {
    int n = 3;
    std::vector<std::string> res = Leetcode::generate_parenthesis(n);
    std::cout << "Generate parentheses: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 23: /problems/merge-k-sorted-lists/
void merge_k_lists() {
    std::vector<std::shared_ptr<ListNode>> lists = {
        Leetcode::vector_to_linked_list({1, 4, 5}),
        Leetcode::vector_to_linked_list({1, 3, 4}),
        Leetcode::vector_to_linked_list({2, 6}),
    };
    std::shared_ptr result = Leetcode::merge_k_lists(lists);
    std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Merge k sorted lists: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 24: /problems/swap-nodes-in-pairs/
void swap_pairs() {
    std::shared_ptr head = Leetcode::vector_to_linked_list({1,2,3,4,5,6});
    std::shared_ptr result = Leetcode::swap_pairs(head);
    std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Swap nodes in pairs: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 26: /problems/remove-duplicates-from-sorted-array/
void remove_duplicates() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int res = Leetcode::remove_duplicates(nums);
    std::cout << "Remove duplicates from sorted array: " << res << std::endl;
}

// 27: /problems/remove-element/
void remove_element() {
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int res = Leetcode::remove_element(nums, val);
    std::cout << "Remove elements: " << res << std::endl;
}

int main() {
    two_sum();
    add_two_numbers();
    length_of_longest_substring();
    longest_palindromic_substring();
    convert();
    reverse();
    my_atoi();
    is_palindrome();
    is_match();
    max_area();
    int_to_roman();
    roman_to_int();
    longest_common_prefix();
    three_sum();
    three_sum_closest();
    letter_combinations();
    four_sum();
    remove_nth_from_end();
    is_valid();
    merge_two_lists();
    generate_parenthesis();
    merge_k_lists();
    swap_pairs();
    remove_duplicates();
    remove_element();
    return 0;
}
