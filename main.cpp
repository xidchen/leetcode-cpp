#include <iostream>
#include "leetcode.h"

// 1: /problems/two-sum/
void two_sum() {
    const std::vector nums = {2, 7, 11, 15};
    constexpr int target = 9;
    const std::vector<int> res = Leetcode::two_sum(nums, target);
    std::cout << "Two sum: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 2: /problems/add-two-numbers/
void add_two_numbers() {
    const std::shared_ptr l1 = Leetcode::vector_to_linked_list({9,9,9,9,9,9,9});
    const std::shared_ptr l2 = Leetcode::vector_to_linked_list({9,9,9,9});
    const std::shared_ptr result = Leetcode::add_two_numbers(l1, l2);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Add two numbers: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 3: /problems/longest-substring-without-repeating-characters/
void length_of_longest_substring() {
    const std::string input = "abcdefabc";
    const int res = Leetcode::length_of_longest_substring(input);
    std::cout << "Length of longest substring: " << res << std::endl;
}

// 5: /problems/longest-palindromic-substring/
void longest_palindromic_substring() {
    const std::string input = "babad";
    const std::string res = Leetcode::longest_palindromic_substring(input);
    std::cout << "Longest palindromic substring: " << res << std::endl;
}

// 6: /problems/zigzag-conversion/
void convert() {
    const std::string input = "PAYPALISHIRING";
    constexpr int num_rows = 3;
    const std::string res = Leetcode::convert(input, num_rows);
    std::cout << "Zigzag conversion: " << res << std::endl;
}

// 7: /problems/reverse-integer/
void reverse() {
    constexpr int x = -2147483648;
    const int res = Leetcode::reverse(x);
    std::cout << "Reverse integer: " << res << std::endl;
}

// 8: /problems/string-to-integer-atoi/
void my_atoi() {
    std::string s = " -273 degree ";
    const int res = Leetcode::my_atoi(s);
    std::cout << "String to integer (atoi): " << res << std::endl;
}

// 9: /problems/palindrome-number/
void is_palindrome() {
    constexpr int x = 121;
    const bool res = Leetcode::is_palindrome(x);
    std::cout << "Is palindrome: " << std::boolalpha << res << std::endl;
}

// 10: /problems/regular-expression-matching/
void is_match() {
    const std::string s = "aa";
    const std::string p = "a*";
    const bool res = Leetcode::is_match(s, p);
    std::cout << "Regular expression matching: " << res << std::endl;
}

// 11: /problems/container-with-most-water/
void max_area() {
    const std::vector height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    const int res = Leetcode::max_area(height);
    std::cout << "Container with most water: " << res << std::endl;
}

// 12: /problems/integer-to-roman/
void int_to_roman() {
    constexpr int num = 2024;
    const std::string res = Leetcode::int_to_roman(num);
    std::cout << "Integer to roman: " << res << std::endl;
}

// 13: /problems/roman-to-integer/
void roman_to_int() {
    const std::string s = "MMXXIV";
    const int res = Leetcode::roman_to_int(s);
    std::cout << "Roman to integer: " << res << std::endl;
}

// 14: /problems/longest-common-prefix/
void longest_common_prefix() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    const std::string res = Leetcode::longest_common_prefix(strs);
    std::cout << "Longest common integer: " << res << std::endl;
}

// 15: /problems/3sum
void three_sum() {
    const std::vector nums = {-1, 0, 1, 2, -1, -4};
    const std::vector<std::vector<int>> res = Leetcode::three_sum(nums);
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
    std::vector nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    constexpr int target = -2;
    const int res = Leetcode::three_sum_closest(nums, target);
    std::cout << "Three sum closest: " << res << std::endl;
}

// 17: /problems/letter-combinations-of-a-phone-number/
void letter_combinations() {
    const std::string digits = "38";
    const std::vector<std::string> res = Leetcode::letter_combinations(digits);
    std::cout << "Letter combinations: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 18: /problems/4sum/
void four_sum() {
    std::vector nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    constexpr int target = 1000000000;
    const std::vector<std::vector<int>> res = Leetcode::four_sum(nums, target);
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
    const std::shared_ptr head = Leetcode::vector_to_linked_list({1,2,3,4,5});
    constexpr int n = 2;
    const std::shared_ptr result = Leetcode::remove_nth_from_end(head, n);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Remove nth node from end of list: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 20: /problems/valid-parentheses/
void is_valid() {
    const std::string s = "()[]{}";
    const bool res = Leetcode::is_valid(s);
    std::cout << "Valid parentheses: " << std::boolalpha << res << std::endl;
}

// 21: /problems/merge-two-sorted-lists/
void merge_two_lists() {
    const std::shared_ptr l1 = Leetcode::vector_to_linked_list({1, 2, 4});
    const std::shared_ptr l2 = Leetcode::vector_to_linked_list({1, 3, 4});
    const std::shared_ptr result = Leetcode::merge_two_lists(l1, l2);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Merge two sorted lists: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 22: /problems/generate-parentheses/
void generate_parenthesis() {
    constexpr int n = 3;
    const std::vector<std::string> res = Leetcode::generate_parenthesis(n);
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
    const std::shared_ptr result = Leetcode::merge_k_lists(lists);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Merge k sorted lists: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 24: /problems/swap-nodes-in-pairs/
void swap_pairs() {
    const std::shared_ptr head = Leetcode::vector_to_linked_list({1,2,3,4,5,6});
    const std::shared_ptr result = Leetcode::swap_pairs(head);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Swap nodes in pairs: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 25: /problems/reverse-nodes-in-k-group/
void reverse_k_group() {
    const std::shared_ptr head = Leetcode::vector_to_linked_list({1,2,3,4,5});
    constexpr int k = 2;
    const std::shared_ptr result = Leetcode::reverse_k_group(head, k);
    const std::vector<int> res = Leetcode::linked_list_to_vector(result);
    std::cout << "Reverse nodes in k group: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 26: /problems/remove-duplicates-from-sorted-array/
void remove_duplicates() {
    std::vector nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const int res = Leetcode::remove_duplicates(nums);
    std::cout << "Remove duplicates from sorted array: " << res << std::endl;
}

// 27: /problems/remove-element/
void remove_element() {
    std::vector nums = {0, 1, 2, 2, 3, 0, 4, 2};
    constexpr int val = 2;
    const int res = Leetcode::remove_element(nums, val);
    std::cout << "Remove elements: " << res << std::endl;
}

// 28: /problems/find-the-index-of-the-first-occurrence-in-a-string/
void str_str() {
    const std::string haystack = "sadness";
    const std::string needle = "sad";
    const int res = Leetcode::str_str(haystack, needle);
    std::cout << "Find the index of the first occurrence in a string: " << res << std::endl;
}

// 29: /problems/divide-two-integers/
void divide() {
    constexpr int dividend = 7;
    constexpr int divisor = -3;
    const int res = Leetcode::divide(dividend, divisor);
    std::cout << "Divide two integers: " << res << std::endl;
}

// 30: /problems/substring-with-concatenation-of-all-words/
void find_substring() {
    const std::string s = "barfoothefoobarman";
    const std::vector<std::string> words = {"foo", "bar"};
    const std::vector<int> res = Leetcode::find_substring(s, words);
    std::cout << "Substring with concatenation of all words: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 31: /problems/next-permutation/
void next_permutation() {
    std::vector nums = {4, 5, 3, 2, 1};
    Leetcode::next_permutation(nums);
    std::cout << "Next permutation: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 32: /problems/longest-valid-parentheses/
void longest_valid_parentheses() {
    const std::string s = ")()())";
    const int res = Leetcode::longest_valid_parentheses(s);
    std::cout << "Longest valid parentheses: " << res << std::endl;
}

// 33: /problems/search-in-rotated-sorted-array/
void search() {
    const std::vector nums = {4, 5, 6, 7, 0, 1, 2};
    constexpr int target = 0;
    const int res = Leetcode::search(nums, target);
    std::cout << "Search in rotated sorted array: " << res << std::endl;
}

// 34: /problems/find-first-and-last-position-of-element-in-sorted-array/
void search_range() {
    const std::vector nums = {5, 7, 7, 8, 8, 10};
    constexpr int target = 8;
    const std::vector<int> res = Leetcode::search_range(nums, target);
    std::cout << "Find first and last position of element in sorted array: [";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 35: /problems/search-insert-position/
void search_insert() {
    const std::vector nums = {1, 3, 5, 6};
    constexpr int target = 0;
    const int res = Leetcode::search_insert(nums, target);
    std::cout << "Search insert position: " << res << std::endl;
}

// 36: /problems/valid-sudoku/
void is_valid_sudoku() {
    const std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    const bool res = Leetcode::is_valid_sudoku(board);
    std::cout << "Valid sudoku: " << std::boolalpha << res << std::endl;
}

// 37: /problems/sudoku-solver/
void solve_sudoku() {
    std::vector<std::vector<char>> board = {
        {'4','5','.','.','.','9','3','.','1'},
        {'.','.','.','.','8','.','9','.','.'},
        {'.','2','.','.','.','.','.','.','.'},
        {'.','.','2','.','.','4','.','.','.'},
        {'.','.','8','.','.','.','.','.','3'},
        {'3','4','.','.','7','.','.','5','.'},
        {'1','9','.','.','.','8','.','.','5'},
        {'.','.','3','.','.','.','.','.','.'},
        {'.','.','.','6','.','.','.','7','.'},
    };
    Leetcode::solve_sudoku(board);
    std::cout << "Sudoku solver: [" << std::endl;
    for (size_t i = 0; i < board.size(); ++i) {
        std::cout << "\t[";
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << "'" << board[i][j] << "'";
            if (j < board[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < board.size() - 1) std::cout << std::endl;
    }
    std::cout << std::endl << "]" << std::endl;
}

// 38: /problems/count-and-say/
void count_and_say() {
    constexpr int n = 5;
    const std::string res = Leetcode::count_and_say(n);
    std::cout << "Count and say: " << res << std::endl;
}

// 39: /problems/combination-sum/
void combination_sum() {
    const std::vector candidates = {2, 3, 5};
    constexpr int target = 8;
    const std::vector<std::vector<int>> res = Leetcode::combination_sum(candidates, target);
    std::cout << "Combination sum: [";
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

// 40: /problems/combination-sum-ii/
void combination_sum_2() {
    const std::vector candidates = {10, 1, 2, 7, 6, 1, 5};
    constexpr int target = 8;
    const std::vector<std::vector<int>> res = Leetcode::combination_sum_2(candidates, target);
    std::cout << "Combination sum II: [";
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

// 41: /problems/first-missing-positive/
void first_missing_positive() {
    const std::vector nums = {3, 4, -1, 1};
    const int res = Leetcode::first_missing_positive(nums);
    std::cout << "First missing positive: " << res << std::endl;
}

// 42: /problems/trapping-rain-water/
void trap() {
    const std::vector height = {4, 2, 0, 3, 2, 5};
    const int res = Leetcode::trap(height);
    std::cout << "Trapping rain water: " << res << std::endl;
}

// 43: /problems/multiply-strings/
void multiply() {
    const std::string num1 = "123";
    const std::string num2 = "456";
    const std::string res = Leetcode::multiply(num1, num2);
    std::cout << "Multiply strings: " << res << std::endl;
}

// 44: /problems/wildcard-matching/
void is_match_wildcard() {
    const std::string s = "aa";
    const std::string p = "a*";
    const bool res = Leetcode::is_match_wildcard(s, p);
    std::cout << "Wildcard matching: " << std::boolalpha << res << std::endl;
}

// 45: /problems/jump-game-ii/
void jump() {
    const std::vector nums = {2, 3, 1, 1, 4};
    const int res = Leetcode::jump(nums);
    std::cout << "Jump game II: " << res << std::endl;
}

// 46: /problems/permutations/
void permute() {
    std::vector nums = {1, 2, 3};
    const std::vector<std::vector<int>> res = Leetcode::permute(nums);
    std::cout << "Permutations: [";
    for (const auto & r : res) {
        std::cout << "[";
        for (size_t j = 0; j < r.size(); ++j) {
            std::cout << r[j];
            if (j < r.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (r != res.back()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 47: /problems/permutations-ii/
void permute_unique() {
    std::vector nums = {1, 1, 2};
    const std::vector<std::vector<int>> res = Leetcode::permute_unique(nums);
    std::cout << "Permutations II: [";
    for (const auto & r : res) {
        std::cout << "[";
        for (size_t j = 0; j < r.size(); ++j) {
            std::cout << r[j];
            if (j < r.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (r != res.back()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// 48: /problems/rotate-image/
void rotate() {
    std::vector<std::vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };
    Leetcode::rotate(matrix);
    std::cout << "Rotate image: [";
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j];
            if (j < matrix[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < matrix.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

auto main() -> int {
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
    reverse_k_group();
    remove_duplicates();
    remove_element();
    str_str();
    divide();
    find_substring();
    next_permutation();
    longest_valid_parentheses();
    search();
    search_range();
    search_insert();
    is_valid_sudoku();
    solve_sudoku();
    count_and_say();
    combination_sum();
    combination_sum_2();
    first_missing_positive();
    trap();
    multiply();
    is_match_wildcard();
    jump();
    permute();
    permute_unique();
    rotate();
    return 0;
}
