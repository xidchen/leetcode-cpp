#ifndef LEETCODE_H
#define LEETCODE_H

#include "listnode.h"
#include <memory>
#include <string>
#include <vector>

class Leetcode final {
public:
    Leetcode() = default;
    ~Leetcode() = default;

    static auto vector_to_linked_list(const std::vector<int>& nums) -> std::shared_ptr<ListNode>;
    static auto linked_list_to_vector(std::shared_ptr<ListNode> node) -> std::vector<int>;

    // 1: /problems/two-sum/
    static auto two_sum(const std::vector<int>& nums, int target) -> std::vector<int>;

    // 2: /problems/add-two-numbers/
    static auto add_two_numbers(
        std::shared_ptr<ListNode> l1,
        std::shared_ptr<ListNode> l2
    ) -> std::shared_ptr<ListNode>;

    // 3: /problems/longest-substring-without-repeating-characters/
    static auto length_of_longest_substring(const std::string& s) -> int;

    // 5: /problems/longest-palindromic-substring/
    static auto longest_palindromic_substring(const std::string& s) -> std::string;

    // 6: /problems/zigzag-conversion/
    static auto convert(const std::string& s, int num_rows) -> std::string;

    // 7: /problems/reverse-integer/
    static auto reverse(int x) -> int;

    // 8: /problems/string-to-integer-atoi/
    static auto my_atoi(std::string& s) -> int;

    // 9: /problems/palindrome-number/
    static auto is_palindrome(int x) -> bool;

    // 10: /problems/regular-expression-matching/
    static auto is_match(const std::string& s, const std::string& p) -> bool;

    // 11: /problems/container-with-most-water/
    static auto max_area(const std::vector<int>& height) -> int;

    // 12: /problems/integer-to-roman/
    static auto int_to_roman(int num) -> std::string;

    // 13: /problems/roman-to-integer/
    static auto roman_to_int(const std::string& s) -> int;

    // 14: /problems/longest-common-prefix/
    static auto longest_common_prefix(std::vector<std::string>& strs) -> std::string;

    // 15: /problems/3sum
    static auto three_sum(const std::vector<int> &nums) -> std::vector<std::vector<int>>;

    // 16: /problems/3sum-closest/
    static auto three_sum_closest(std::vector<int>& nums, int target) -> int;

    // 17: /problems/letter-combinations-of-a-phone-number/
    static auto letter_combinations(const std::string& digits) -> std::vector<std::string>;

    // 18: /problems/4sum/
    static auto four_sum(std::vector<int>& nums, int target) -> std::vector<std::vector<int>>;

    // 19: /problems/remove-nth-node-from-end-of-list/
    static auto remove_nth_from_end(std::shared_ptr<ListNode> head, int n) -> std::shared_ptr<ListNode>;

    // 20: /problems/valid-parentheses/
    static auto is_valid(const std::string& s) -> bool;

    // 21: /problems/merge-two-sorted-lists/
    static auto merge_two_lists(
        std::shared_ptr<ListNode> l1,
        std::shared_ptr<ListNode> l2
    ) -> std::shared_ptr<ListNode>;

    // 22: /problems/generate-parentheses/
    static auto generate_parenthesis(int n) -> std::vector<std::string>;

    // 23: /problems/merge-k-sorted-lists/
    static auto merge_k_lists(const std::vector<std::shared_ptr<ListNode>>& lists) -> std::shared_ptr<ListNode>;

    // 24: /problems/swap-nodes-in-pairs/
    static auto swap_pairs(std::shared_ptr<ListNode> head) -> std::shared_ptr<ListNode>;

    // 25: /problems/reverse-nodes-in-k-group/
    static auto reverse_k_group(std::shared_ptr<ListNode> head, int k) -> std::shared_ptr<ListNode>;

    // 26: /problems/remove-duplicates-from-sorted-array/
    static auto remove_duplicates(std::vector<int>& nums) -> int;

    // 27: /problems/remove-element/
    static auto remove_element(std::vector<int>& nums, int val) -> int;

    // 28: /problems/find-the-index-of-the-first-occurrence-in-a-string/
    static auto str_str(const std::string& haystack, const std::string& needle) -> int;

    // 29: /problems/divide-two-integers/
    static auto divide(int dividend, int divisor) -> int;

    // 30: /problems/substring-with-concatenation-of-all-words/
    static auto find_substring(const std::string& s, const std::vector<std::string>& words) -> std::vector<int>;

    // 31: /problems/next-permutation/
    static void next_permutation(std::vector<int>& nums);

    // 32: /problems/longest-valid-parentheses/
    static auto longest_valid_parentheses(const std::string& s) -> int;

    // 33: /problems/search-in-rotated-sorted-array/
    static auto search(const std::vector<int>& nums, int target) -> int;

    // 34: /problems/find-first-and-last-position-of-element-in-sorted-array/
    static auto search_range(const std::vector<int>& nums, int target) -> std::vector<int>;

    // 35: /problems/search-insert-position/
    static auto search_insert(const std::vector<int>& nums, int target) -> int;

    // 36: /problems/valid-sudoku/
    static auto is_valid_sudoku(const std::vector<std::vector<char>>& board) -> bool;

    // 37: /problems/sudoku-solver/
    static void solve_sudoku(std::vector<std::vector<char>>& board);

    // 38： /problems/count-and-say/
    static auto count_and_say(int n) -> std::string;

    // 39: /problems/combination-sum/
    static auto combination_sum(const std::vector<int>& candidates, int target) -> std::vector<std::vector<int>>;

    // 40: /problems/combination-sum-ii/
    static auto combination_sum_2(const std::vector<int>& candidates, int target) -> std::vector<std::vector<int>>;

    // 41: /problems/first-missing-positive/
    static auto first_missing_positive(const std::vector<int>& nums) -> int;

    // 42: /problems/trapping-rain-water/
    static auto trap(const std::vector<int>& height) -> int;

    // 43: /problems/multiply-strings/
    static auto multiply(const std::string& num1, const std::string& num2) -> std::string;

    // 44: /problems/wildcard-matching/
    static auto is_match_wildcard(const std::string& s, const std::string& p) -> bool;

    // 45: /problems/jump-game-ii/
    static auto jump(const std::vector<int> &nums) -> int;

    // 46: /problems/permutations/
    static auto permute(std::vector<int>& nums) -> std::vector<std::vector<int>>;

    // 47: /problems/permutations-ii/
    static auto permute_unique(std::vector<int>& nums) -> std::vector<std::vector<int>>;

    // 48: /problems/rotate-image/
    static auto rotate(std::vector<std::vector<int>>& matrix) -> void;

    // 49: /problems/group-anagrams/
    static auto group_anagrams(const std::vector<std::string> &strs) -> std::vector<std::vector<std::string>>;

    // 50: /problems/powx-n/
    static auto my_pow(double base_value, int exponent) -> double;

    // 51: /problems/n-queens/
    static auto solve_n_queens(int n) -> std::vector<std::vector<std::string>>;

    // 52: /problems/n-queens-ii/
    static auto total_n_queens(int n) -> int;

    // 53: /problems/maximum-subarray/
    static auto max_sub_array(const std::vector<int>& nums) -> int;

    // 54: /problems/spiral-matrix/
    static auto spiral_order(std::vector<std::vector<int>>& matrix) -> std::vector<int>;

private:
    // 23: /problems/merge-k-sorted-lists/
    struct Compare {
        auto operator()(const std::shared_ptr<ListNode> &a, const std::shared_ptr<ListNode> &b) const -> bool {
            return a->val > b->val;
        }
    };
};

#endif
