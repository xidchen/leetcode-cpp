#include "leetcode.h"
#include "listnode.h"
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Private functions
static std::vector<std::vector<int>> two_sum(const std::vector<long long>& n, const long long t) {
    std::vector<std::vector<int>> res;
    size_t lo = 0, hi = n.size() - 1;
    while (lo < hi) {
        if (const long long sum = n[lo] + n[hi]; sum < t || (lo > 0 && n[lo] == n[lo - 1])) ++lo;
        else if (sum > t || (hi < n.size() - 1 && n[hi] == n[hi + 1])) --hi;
        else {
            res.push_back({static_cast<int>(n[lo]), static_cast<int>(n[hi])});
            ++lo;
            --hi;
        }
    }
    return res;
}

static std::vector<std::vector<int>> k_sum(std::vector<long long>& n, const long long t, const long long k) {
    std::vector<std::vector<int>> res;
    if (n.size() < static_cast<size_t>(k) || t < n[0] * k || n[n.size() - 1] * k < t) return res;
    if (k == 2) return two_sum(n, t);
    for (size_t i = 0; i < n.size(); ++i) {
        if (i == 0 || n[i - 1] != n[i]) {
            auto start = n.begin();
            std::advance(start, i + 1);
            auto sliced_vector = std::vector(start, n.end());
            for (auto& set : k_sum(sliced_vector, t - n[i], k - 1)) {
                set.insert(set.begin(), static_cast<int>(n[i]));
                res.push_back(set);
            }
        }
    }
    return res;
}

static void backtrack_parenthesis(
    std::vector<std::string>& result, const std::string& s, const int left, const int right, const int n
) {
    if (s.length() == n * 2) {
        result.push_back(s);
        return;
    }
    if (left < n) backtrack_parenthesis(result, s + "(", left + 1, right, n);
    if (right < left) backtrack_parenthesis(result, s + ")", left, right + 1, n);
}

// Public functions
std::shared_ptr<ListNode> Leetcode::vector_to_linked_list(const std::vector<int>& nums) {
    const auto dummy = std::make_shared<ListNode>(0);
    std::shared_ptr current = dummy;
    for (int num : nums) {
        current->next = std::make_shared<ListNode>(num);
        current = current->next;
    }
    return dummy->next;
}

std::vector<int> Leetcode::linked_list_to_vector(std::shared_ptr<ListNode> node) {
    std::vector<int> result;
    while (node != nullptr) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

// 1: /problems/two-sum/
std::vector<int> Leetcode::two_sum(const std::vector<int>& nums, const int target) {
    std::unordered_map<int, int> dic;
    for (int i = 0; i < nums.size(); ++i) {
        if (dic.find(nums[i]) != dic.end()) {
            return {dic[nums[i]], i};
        }
        dic[target - nums[i]] = i;
    }
    return {};
}

// 2: /problems/add_two_numbers/
std::shared_ptr<ListNode> Leetcode::add_two_numbers(
    std::shared_ptr<ListNode> l1,
    std::shared_ptr<ListNode> l2
) {
    const auto dummy = std::make_shared<ListNode>(0);
    std::shared_ptr current = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        if (l1 != nullptr) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            carry += l2->val;
            l2 = l2->next;
        }
        current->next = std::make_shared<ListNode>(carry % 10);
        current = current->next;
        carry /= 10;
    }
    return dummy->next;
}

// 3: /problems/longest-substring-without-repeating-characters/
int Leetcode::length_of_longest_substring(const std::string& s) {
    std::unordered_map<char, int> last_seen;
    int start = 0, longest = 0;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (last_seen.find(c) != last_seen.end() &&
            last_seen[c] >= start) {
            start = last_seen[c] + 1;
        } else {
            longest = std::max(longest, i - start + 1);
        }
        last_seen[c] = i;
    }
    return longest;
}

// 5: /problems/longest-palindromic-substring/
std::string Leetcode::longest_palindromic_substring(const std::string& s) {
    if (s.length() < 2 || s == std::string(s.rbegin(), s.rend())) {
        return s;
    }
    int start = -1, ml = 0;
    for (int i = 0; i < s.length(); i++) {
        std::string odd, even;
        if (i - ml - 1 >= 0) {
            odd = s.substr(i - ml - 1, ml + 2);
        }
        if (i - ml >= 0) {
            even = s.substr(i - ml, ml + 1);
        }
        if (!odd.empty() && odd == std::string(
                odd.rbegin(), odd.rend())) {
            start = i - ml - 1;
            ml += 2;
            continue;
        }
        if (!even.empty() && even == std::string(
                even.rbegin(), even.rend())) {
            start = i - ml;
            ml += 1;
        }
    }
    return s.substr(start, ml);
}

// 6: /problems/zigzag-conversion/
std::string Leetcode::convert(const std::string& s, const int num_rows) {
    if (num_rows == 1 || s.length() < num_rows) {
        return s;
    }
    std::vector<std::string> zigzag(num_rows, "");
    int row = 0;
    int step = 1;
    for (const char c : s) {
        zigzag[row] += c;
        if (row == 0) {
            step = 1;
        }
        if (row == num_rows - 1) {
            step = -1;
        }
        row += step;
    }
    std::string res;
    for (const std::string& str : zigzag) {
        res += str;
    }
    return res;
}

// 7: /problems/reverse-integer/
int Leetcode::reverse(int x) {
    if (x == INT_MIN) return 0;
    const bool negative = x < 0;
    x = abs(x);
    long long y = 0;
    while (x != 0) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    if (y > INT_MAX) return 0;
    return negative ? static_cast<int>(-y) : static_cast<int>(y);
}

// 8: /problems/string-to-integer-atoi/
int Leetcode::my_atoi(std::string& s) {
    s.erase(0, s.find_first_not_of(' '));
    if (s.empty()) return 0;
    int i = 0, sign = 1;
    if (s[i] == '+' || s[i] == '-') sign = (s[i++] == '+') ? 1: -1;
    long long res = 0;
    while (i < s.length() && isdigit(s[i])) {
        res = res * 10 + (s[i++] - '0');
        if (res * sign > INT_MAX) return INT_MAX;
        if (res * sign < INT_MIN) return INT_MIN;
    }
    return static_cast<int>(res * sign);
}

// 9: /problems/palindrome-number/
bool Leetcode::is_palindrome(const int x) {
    std::string s = std::to_string(x);
    return s == std::string(s.rbegin(), s.rend());
}

// 10: /problems/regular-expression-matching/
bool Leetcode::is_match(const std::string& s, const std::string& p) {
    std::vector<std::vector<bool>> dp(
        s.length() + 1,
        std::vector<bool>(p.length() + 1, false));
    dp[s.length()][p.length()] = true;
    for (size_t i = s.length(); i != static_cast<size_t>(-1); --i) {
        for (size_t j = p.length() - 1; j != static_cast<size_t>(-1); --j) {
            const bool first_match = i < s.length() && (p[j] == s[i] || p[j] == '.');
            if (j + 1 < p.length() && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
            } else {
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}

// 11: /problems/container-with-most-water/
int Leetcode::max_area(const std::vector<int>& height) {
    int max_area = 0;
    size_t i = 0, j = height.size() - 1;
    while (i < j) {
        max_area = std::max(
            max_area,
            std::min(height[i], height[j]) * static_cast<int>(j - i));
        if (height[i] < height[j]) i++;
        else j--;
    }
    return max_area;
}

// 12: /problems/integer-to-roman/
std::string Leetcode::int_to_roman(int num) {
    std::vector<std::pair<int, std::string>> mapping {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"},
        {1, "I"},
    };
    std::string romans;
    for (const auto&[fst, snd] : mapping) {
        while (fst <= num) {
            num -= fst;
            romans += snd;
        }
    }
    return romans;
}

// 13: /problems/roman-to-integer/
int Leetcode::roman_to_int(const std::string& s) {
    std::unordered_map<char, int> d = {
        {'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500},
        {'M', 1000},
    };
    int integer = 0, prev_int = 0;
    for (std::string::size_type i = s.size(); i-- > 0;) {
        if (char roman = s[i]; d[roman] >= prev_int) {
            prev_int = d[roman];
            integer += d[roman];
        } else {
            integer -= d[roman];
        }
    }
    return integer;
}

// 14: /problems/longest-common-prefix/
std::string Leetcode::longest_common_prefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];
    std::sort(strs.begin(), strs.end());
    std::string result;
    for (size_t i = 0; i < strs[0].size() && i < strs.back().size(); i++) {
        if (strs[0][i] == strs.back()[i]) result.push_back(strs[0][i]);
        else break;
    }
    return result;
}

// 15: /problems/3sum
std::vector<std::vector<int>> Leetcode::three_sum(std::vector<int>& nums) {
    std::unordered_map<int, int> dic;
    std::vector<std::vector<int>> res;
    for (int n : nums) dic[n]++;
    std::vector<int> sorted_nums;
    sorted_nums.reserve(dic.size());
    for (auto&[fst, snd] : dic) {
        sorted_nums.push_back(fst);
    }
    std::sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 0; i < sorted_nums.size(); ++i) {
        int x = sorted_nums[i];
        if (x == 0 && dic[x] > 2) res.push_back({0, 0, 0});
        else if (x != 0 && dic[x] > 1 && dic.count(-2 * x) > 0) {
            res.push_back({x, x, -2 * x});
        }
        if (x < 0) {
            const auto left = std::lower_bound(
                sorted_nums.begin() + i + 1,
                sorted_nums.end(),
                -x - *sorted_nums.rbegin());
            auto right = std::upper_bound(
                sorted_nums.begin() + i + 1,
                sorted_nums.end(),
                x / -2);
            for (auto it = left; it != right; ++it) {
                int y = *it;
                if (int z = -x - y; dic.count(z) > 0 && z != y) {
                    res.push_back({x, y, z});
                }
            }
        }
    }
    return res;
}

// 16: /problems/3sum-closest/
int Leetcode::three_sum_closest(std::vector<int>& nums, const int target) {
    const int n = static_cast<int>(nums.size());
    std::sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1, k = n - 1;
        if (nums[i] + nums[j] + nums[j + 1] >= target) k = j + 1;
        if (nums[i] + nums[k - 1] + nums[k] <= target) j = k - 1;
        while (j < k) {
            const int s = nums[i] + nums[j] + nums[k];
            if (abs(target - s) < (abs(target - res))) res = s;
            if (s == target) return res;
            if (s < target) ++j;
            if (s > target) --k;
        }
    }
    return res;
}

// 17: /problems/letter-combinations-of-a-phone-number/
std::vector<std::string> Leetcode::letter_combinations(std::string& digits) {
    std::vector<std::string> results;
    if (digits.empty() ||
        digits.find('0') != std::string::npos ||
        digits.find('1') != std::string::npos) {
        return results;
    }
    std::unordered_map<char, std::vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    results.emplace_back("");
    for (char digit : digits) {
        std::vector<std::string> temp;
        for (const std::string& result : results) {
            for (const char letter : mapping[digit]) {
                temp.push_back(result + letter);
            }
        }
        results = temp;
    }
    return results;
}

// 18: /problems/4sum/
std::vector<std::vector<int>> Leetcode::four_sum(std::vector<int>& nums, const int target) {
    std::vector<long long> nums64 (nums.begin(), nums.end());
    std::sort(nums64.begin(), nums64.end());
    return k_sum(nums64, target, 4);
}

// 19: /problems/remove-nth-node-from-end-of-list/
std::shared_ptr<ListNode> Leetcode::remove_nth_from_end(
    std::shared_ptr<ListNode> head, const int n
) {
    const auto dummy = std::make_shared<ListNode>(0);
    dummy->next = std::move(head);
    std::shared_ptr<ListNode> first = dummy;
    std::shared_ptr<ListNode> second = dummy;
    for (int i = 0; i < n; ++i) {
        if (first->next != nullptr) first = first->next;
        else return dummy->next;
    }
    while (first->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    if (second->next != nullptr) second->next = second->next->next;
    return dummy->next;
}

// 20: /problems/valid-parentheses/
bool Leetcode::is_valid(const std::string& s) {
    std::unordered_map<char, char> d = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };
    std::stack<char> stack;
    for (char c : s) {
        if (d.find(c) != d.end()) stack.push(c);
        else {
            if (stack.empty() || d[stack.top()] != c) return false;
            stack.pop();
        }
    }
    return stack.empty();
}

// 21: /problems/merge-two-sorted-lists/
std::shared_ptr<ListNode> Leetcode::merge_two_lists(
    std::shared_ptr<ListNode> l1,
    std::shared_ptr<ListNode> l2
) {
    const auto dummy = std::make_shared<ListNode>(0);
    std::shared_ptr<ListNode> prev = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 ? l1 : l2;
    return dummy->next;
}

// 22: /problems/generate-parentheses/
std::vector<std::string> Leetcode::generate_parenthesis(int n) {
    std::vector<std::string> result;
    backtrack_parenthesis(result, "", 0, 0, n);
    return result;
}

// 23: /problems/merge-k-sorted-lists/
std::shared_ptr<ListNode> Leetcode::merge_k_lists(std::vector<std::shared_ptr<ListNode>>& lists) {
    std::priority_queue<std::shared_ptr<ListNode>, std::vector<std::shared_ptr<ListNode>>, Compare> heap;
    for (const auto& list : lists) {
        if (list != nullptr) heap.push(list);
    }
    const auto dummy = std::make_shared<ListNode>(0);
    auto prev = dummy;
    while (!heap.empty()) {
        const auto node = heap.top();
        heap.pop();
        prev->next = node;
        prev = prev->next;
        if (node->next != nullptr) heap.push(node->next);
    }
    return dummy->next;
}

// 24: /problems/swap-nodes-in-pairs/
std::shared_ptr<ListNode> Leetcode::swap_pairs(std::shared_ptr<ListNode> head) {
    const auto dummy = std::make_shared<ListNode>(0);
    dummy->next = std::move(head);
    std::shared_ptr<ListNode> prev = dummy;
    while (prev->next && prev->next->next) {
        const std::shared_ptr<ListNode> first = prev->next;
        const std::shared_ptr<ListNode> second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy->next;
}

// 26: /problems/remove-duplicates-from-sorted-array/
int Leetcode::remove_duplicates(std::vector<int>& nums) {
    int next_new = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[next_new] = nums[i];
            next_new += 1;
        }
    }
    return next_new;
}

// 27: /problems/remove-element/
int Leetcode::remove_element(std::vector<int> &nums, const int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

// 28: /problems/find-the-index-of-the-first-occurrence-in-a-string/
int Leetcode::str_str(const std::string& haystack, const std::string& needle) {
    const size_t found = haystack.find(needle);
    if (found == std::string::npos) return -1;
    return static_cast<int>(found);
}

// 29: /problems/divide-two-integers/
int Leetcode::divide(const int dividend, const int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    const bool diff_sign = (dividend < 0) ^ (divisor < 0);
    long long abs_dividend = std::abs(static_cast<long long>(dividend));
    const long long abs_divisor = std::abs(static_cast<long long>(divisor));
    int res = 0;
    long long max_divisor = abs_divisor;
    int shift_count = 1;
    while (abs_dividend >= (max_divisor << 1)) {
        max_divisor <<= 1;
        shift_count <<= 1;
    }
    while (shift_count >= 1) {
        if (abs_dividend >= max_divisor) {
            abs_dividend -= max_divisor;
            res += shift_count;
        }
        shift_count >>= 1;
        max_divisor >>= 1;
    }
    if (diff_sign) res = -res;
    return std::max(std::min(res, INT_MAX), INT_MIN);
}

// 30: /problems/substring-with-concatenation-of-all-words/
std::vector<int> Leetcode::find_substring(const std::string& s, const std::vector<std::string>& words) {
    std::vector<int> res;
    if (words.empty() || s.length() < words.size() * words[0].length()) return res;
    const int wc = static_cast<int>(words.size());
    const int wl = static_cast<int>(words[0].length());
    const int sl = static_cast<int>(s.length());
    std::pmr::unordered_map<std::string, int> wd;
    for (const auto& w : words) wd[w]++;
    for (int i = 0; i < wl; ++i) {
        int start = i, cnt = 0;
        std::pmr::unordered_map<std::string, int> tmp_dict;
        for (int j = i; j <= sl - wl; j += wl) {
            if (const std::string word = s.substr(j, wl); wd.find(word) != wd.end()) {
                cnt++;
                tmp_dict[word]++;
                while (tmp_dict[word] > wd[word]) {
                    tmp_dict[s.substr(start, wl)]--;
                    start += wl;
                    cnt--;
                }
                if (cnt == wc) {
                    res.push_back(start);
                    tmp_dict[s.substr(start, wl)]--;
                    start += wl;
                    cnt--;
                }
            } else {
                start = j + wl;
                cnt = 0;
                tmp_dict.clear();
            }
        }
    }
    return res;
}
