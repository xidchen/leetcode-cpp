#ifndef LEETCODE_H
#define LEETCODE_H

#include "listnode.h"
#include <memory>
#include <string>
#include <vector>

class Leetcode {
public:
    Leetcode() = default;
    virtual ~Leetcode() = default;

    static std::shared_ptr<ListNode> vector_to_linked_list(const std::vector<int>& nums);
    static std::vector<int> linked_list_to_vector(std::shared_ptr<ListNode> node);

    // 1: /problems/two-sum/
    static std::vector<int> two_sum(std::vector<int>& nums, int target);

    // 2: /problems/add-two-numbers/
    static std::shared_ptr<ListNode> add_two_numbers(
        std::shared_ptr<ListNode> l1,
        std::shared_ptr<ListNode> l2
    );

    // 3: /problems/longest-substring-without-repeating-characters/
    static int length_of_longest_substring(const std::string& s);

    // 5: /problems/longest-palindromic-substring/
    static std::string longest_palindromic_substring(const std::string& s);

    // 6: /problems/zigzag-conversion/
    static std::string convert(const std::string& s, int num_rows);

    // 7: /problems/reverse-integer/
    static int reverse(int x);

    // 8: /problems/string-to-integer-atoi/
    static int my_atoi(std::string& s);

    // 9: /problems/palindrome-number/
    static bool is_palindrome(int x);

    // 10: /problems/regular-expression-matching/
    static bool is_match(const std::string& s, const std::string& p);

    // 11: /problems/container-with-most-water/
    static int max_area(const std::vector<int>& height);

    // 12: /problems/integer-to-roman/
    static std::string int_to_roman(int num);

    // 13: /problems/roman-to-integer/
    static int roman_to_int(const std::string& s);

    // 14: /problems/longest-common-prefix/
    static std::string longest_common_prefix(std::vector<std::string>& strs);

    // 15: /problems/3sum
    static std::vector<std::vector<int>> three_sum(std::vector<int>& nums);

    // 16: /problems/3sum-closest/
    static int three_sum_closest(std::vector<int>& nums, int target);

    // 17: /problems/letter-combinations-of-a-phone-number/
    static std::vector<std::string> letter_combinations(std::string& digits);

    // 18: /problems/4sum/
    static std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target);

    // 19: /problems/remove-nth-node-from-end-of-list/
    static std::shared_ptr<ListNode> remove_nth_from_end(std::shared_ptr<ListNode> head, int n);

    // 20: /problems/valid-parentheses/
    static bool is_valid(const std::string& s);

    // 21: /problems/merge-two-sorted-lists/
    static std::shared_ptr<ListNode> merge_two_lists(
        std::shared_ptr<ListNode> l1,
        std::shared_ptr<ListNode> l2
    );

    // 22: /problems/generate-parentheses/
    static std::vector<std::string> generate_parenthesis(int n);

    // 23: /problems/merge-k-sorted-lists/
    static std::shared_ptr<ListNode> merge_k_lists(std::vector<std::shared_ptr<ListNode>>& lists);

    // 24: /problems/swap-nodes-in-pairs/
    static std::shared_ptr<ListNode> swap_pairs(std::shared_ptr<ListNode> head);

    // 26: /problems/remove-duplicates-from-sorted-array/
    static int remove_duplicates(std::vector<int>& nums);

    // 27: /problems/remove-element/
    static int remove_element(std::vector<int>& nums, int val);

private:
    // 23: /problems/merge-k-sorted-lists/
    struct Compare {
        bool operator()(const std::shared_ptr<ListNode>& a, const std::shared_ptr<ListNode>& b) {
            return a->val > b->val;
        }
    };
};

#endif
