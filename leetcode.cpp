#include "leetcode.h"
#include "listnode.h"
#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// Private functions
static auto two_sum(
    const std::vector<long long>& n, const long long t
) -> std::vector<std::vector<int>> {
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

static auto k_sum(
    std::vector<long long>& n, const long long t, const long long k
) -> std::vector<std::vector<int>> {
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
    std::vector<std::string>& result, const std::string& s,
    const int left, const int right, const int n
) {
    if (s.length() == static_cast<size_t>(n) * 2) {
        result.push_back(s);
        return;
    }
    if (left < n) backtrack_parenthesis(result, s + "(", left + 1, right, n);
    if (right < left) backtrack_parenthesis(result, s + ")", left, right + 1, n);
}

static auto solve_board(
    std::vector<std::vector<char>>& board,
    std::array<std::array<bool, 9>, 9>& row_used,
    std::array<std::array<bool, 9>, 9>& col_used,
    std::array<std::array<bool, 9>, 9>& box_used
) -> bool {
    int row = -1, col = -1;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) break;
    }
    if (row == -1) return true;
    const int box_idx = (row / 3) * 3 + col / 3;
    for (int digit = 0; digit < 9; digit++) {
        if (!row_used[row][digit] && !col_used[col][digit] && !box_used[box_idx][digit]) {
            board[row][col] = static_cast<char>('1' + digit);
            row_used[row][digit] = true;
            col_used[col][digit] = true;
            box_used[box_idx][digit] = true;
            if (solve_board(board, row_used, col_used, box_used)) {
                return true;
            }
            board[row][col] = '.';
            row_used[row][digit] = false;
            col_used[col][digit] = false;
            box_used[box_idx][digit] = false;
        }
    }
    return false;
}

static void backtrack_permute(
    std::vector<int>& nums, int start, std::vector<std::vector<int>>& res
) {
    if (start == static_cast<int>(nums.size())) {res.push_back(nums);}
    else {
        for (int i = start; i < static_cast<int>(nums.size()); i++) {
            std::swap(nums[start], nums[i]);
            backtrack_permute(nums, start + 1, res);
            std::swap(nums[start], nums[i]);
        }
    }
}

static void backtrack_permute_unique(
    std::vector<int>& nums, int start, std::vector<std::vector<int>>& res
) {
    std::unordered_set<int> used;
    if (start == static_cast<int>(nums.size())) {
        res.push_back(nums);
        return;
    }
    for (int i = start; i < static_cast<int>(nums.size()); i++) {
        if (used.find(nums[i]) != used.end()) continue;
        used.insert(nums[i]);
        std::swap(nums[start], nums[i]);
        backtrack_permute_unique(nums, start + 1, res);
        std::swap(nums[start], nums[i]);
    }
}


// Public functions
auto Leetcode::vector_to_linked_list(
    const std::vector<int>& nums
) -> std::shared_ptr<ListNode> {
    const auto dummy = std::make_shared<ListNode>(0);
    std::shared_ptr current = dummy;
    for (int num : nums) {
        current->next = std::make_shared<ListNode>(num);
        current = current->next;
    }
    return dummy->next;
}

auto Leetcode::linked_list_to_vector(
    std::shared_ptr<ListNode> node
) -> std::vector<int> {
    std::vector<int> result;
    while (node != nullptr) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

// 1: /problems/two-sum/
auto Leetcode::two_sum(
    const std::vector<int>& nums, const int target
) -> std::vector<int> {
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
auto Leetcode::add_two_numbers(
    std::shared_ptr<ListNode> l1,
    std::shared_ptr<ListNode> l2
) -> std::shared_ptr<ListNode> {
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
auto Leetcode::length_of_longest_substring(const std::string& s) -> int {
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
auto Leetcode::longest_palindromic_substring(const std::string& s) -> std::string {
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
auto Leetcode::convert(const std::string& s, const int num_rows) -> std::string {
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
auto Leetcode::reverse(int x) -> int {
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
auto Leetcode::my_atoi(std::string& s) -> int {
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
auto Leetcode::is_palindrome(const int x) -> bool {
    std::string s = std::to_string(x);
    return s == std::string(s.rbegin(), s.rend());
}

// 10: /problems/regular-expression-matching/
auto Leetcode::is_match(const std::string& s, const std::string& p) -> bool {
    std::vector dp(s.length() + 1, std::vector<bool>(p.length() + 1, false));
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
auto Leetcode::max_area(const std::vector<int>& height) -> int {
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
auto Leetcode::int_to_roman(int num) -> std::string {
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
auto Leetcode::roman_to_int(const std::string& s) -> int {
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
auto Leetcode::longest_common_prefix(std::vector<std::string>& strs) -> std::string {
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
auto Leetcode::three_sum(const std::vector<int>& nums) -> std::vector<std::vector<int>> {
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
auto Leetcode::three_sum_closest(std::vector<int>& nums, const int target) -> int {
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
auto Leetcode::letter_combinations(
    const std::string& digits
) -> std::vector<std::string> {
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
auto Leetcode::four_sum(
    std::vector<int>& nums, const int target
) -> std::vector<std::vector<int>> {
    std::vector<long long> nums64 (nums.begin(), nums.end());
    std::sort(nums64.begin(), nums64.end());
    return k_sum(nums64, target, 4);
}

// 19: /problems/remove-nth-node-from-end-of-list/
auto Leetcode::remove_nth_from_end(
    std::shared_ptr<ListNode> head, const int n
) -> std::shared_ptr<ListNode> {
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
auto Leetcode::is_valid(const std::string& s) -> bool {
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
auto Leetcode::merge_two_lists(
    std::shared_ptr<ListNode> l1,
    std::shared_ptr<ListNode> l2
) -> std::shared_ptr<ListNode> {
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
auto Leetcode::generate_parenthesis(const int n) -> std::vector<std::string> {
    std::vector<std::string> result;
    backtrack_parenthesis(result, "", 0, 0, n);
    return result;
}

// 23: /problems/merge-k-sorted-lists/
auto Leetcode::merge_k_lists(
    const std::vector<std::shared_ptr<ListNode>>& lists
) -> std::shared_ptr<ListNode> {
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
auto Leetcode::swap_pairs(std::shared_ptr<ListNode> head) -> std::shared_ptr<ListNode> {
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

// 25: /problems/reverse-nodes-in-k-group/
auto Leetcode::reverse_k_group(
    std::shared_ptr<ListNode> head, const int k
) -> std::shared_ptr<ListNode> {
    if (k < 2) return head;
    std::shared_ptr<ListNode> node = head;
    for (int i = 0; i < k; ++i) {
        if (!node) return head;
        node = node->next;
    }
    std::shared_ptr<ListNode> prev = reverse_k_group(node, k);
    for (int i = 0; i < k; ++i) {
        const std::shared_ptr<ListNode> temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

// 26: /problems/remove-duplicates-from-sorted-array/
auto Leetcode::remove_duplicates(std::vector<int>& nums) -> int {
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
auto Leetcode::remove_element(std::vector<int> &nums, const int val) -> int {
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
auto Leetcode::str_str(const std::string& haystack, const std::string& needle) -> int {
    const size_t found = haystack.find(needle);
    if (found == std::string::npos) return -1;
    return static_cast<int>(found);
}

// 29: /problems/divide-two-integers/
auto Leetcode::divide(const int dividend, const int divisor) -> int {
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
auto Leetcode::find_substring(
    const std::string& s, const std::vector<std::string>& words
) -> std::vector<int> {
    std::vector<int> res;
    if (words.empty() || s.length() < words.size() * words[0].length()) return res;
    const int wc = static_cast<int>(words.size());
    const int wl = static_cast<int>(words[0].length());
    const int sl = static_cast<int>(s.length());
    std::unordered_map<std::string, int> wd;
    for (const auto& w : words) wd[w]++;
    for (int i = 0; i < wl; ++i) {
        int start = i, cnt = 0;
        std::unordered_map<std::string, int> tmp_dict;
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

// 31: /problems/next-permutation/
void Leetcode::next_permutation(std::vector<int>& nums) {
    if (nums.empty()) return;
    std::size_t i = nums.size();
    if (i < 2) return;
    i -= 2;
    while (i != static_cast<std::size_t>(-1) && nums[i] >= nums[i + 1]) i--;
    if (i != static_cast<std::size_t>(-1)) {
        std::size_t j = nums.size() - 1;
        while (nums[j] <= nums[i]) j--;
        std::swap(nums[i], nums[j]);
    }
    std::reverse(nums.begin() + static_cast<std::ptrdiff_t>(i + 1), nums.end());
}

// 32: /problems/longest-valid-parentheses/
auto Leetcode::longest_valid_parentheses(const std::string &s) -> int {
    std::stack<int> stack;
    stack.push(-1);
    int max_len = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') stack.push(i);
        else {
            stack.pop();
            if (stack.empty()) stack.push(i);
            else max_len = std::max(max_len, i - stack.top());
        }
    }
    return max_len;
}

// 33: /problems/search-in-rotated-sorted-array/
auto Leetcode::search(const std::vector<int>& nums, const int target) -> int {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        const int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

// 34: /problems/find-first-and-last-position-of-element-in-sorted-array/
auto Leetcode::search_range(
    const std::vector<int>& nums, const int target
) -> std::vector<int> {
    auto binary = [&](const double tgt, int left, int right) -> int {
        while (left <= right) {
            if (const int mid = (left + right) / 2; nums[mid] < tgt) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    };
    const int n = static_cast<int>(nums.size());
    const int lower = binary(static_cast<double>(target) - 0.5, 0, n - 1);
    const int upper = binary(static_cast<double>(target) + 0.5, 0, n - 1);
    if (lower == upper) return std::vector{-1, -1};
    return std::vector{lower, upper - 1};
}

// 35: /problems/search-insert-position/
auto Leetcode::search_insert(const std::vector<int>& nums, const int target) -> int {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        const int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// 36: /problems/valid-sudoku/
auto Leetcode::is_valid_sudoku(
    const std::vector<std::vector<char>>& board
) -> bool {
    std::vector<std::vector<char>> rows(9), cols(9), boxes(9);
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char digit = board[r][c];
            if (digit == '.') continue;
            const int b = r / 3 * 3 + c / 3;
            if (std::find(rows[r].begin(), rows[r].end(), digit) != rows[r].end() ||
            std::find(cols[c].begin(), cols[c].end(), digit) != cols[c].end() ||
            std::find(boxes[b].begin(), boxes[b].end(), digit) != boxes[b].end()) return false;
            rows[r].push_back(digit);
            cols[c].push_back(digit);
            boxes[b].push_back(digit);
        }
    }
    return true;
}

// 37: /problems/sudoku-solver/
void Leetcode::solve_sudoku(std::vector<std::vector<char>> &board) {
    std::array<std::array<bool, 9>, 9> row_used = {{false}};
    std::array<std::array<bool, 9>, 9> col_used = {{false}};
    std::array<std::array<bool, 9>, 9> box_used = {{false}};
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] != '.') {
                const int digit = board[r][c] - '1';
                const int box_idx = (r / 3) * 3 + c / 3;
                row_used[r][digit] = true;
                col_used[c][digit] = true;
                box_used[box_idx][digit] = true;
            }
        }
    }
    solve_board(board, row_used, col_used, box_used);
}

// 38： /problems/count-and-say/
auto Leetcode::count_and_say(const int n) -> std::string {
    std::vector seq = {1};
    for (int i = 1; i < n; ++i) {
        std::vector<int> next;
        for (int num : seq) {
            if (next.empty() || next.back() != num) {
                next.push_back(1);
                next.push_back(num);
            } else next[next.size() - 2]++;
        }
        seq = std::move(next);
    }
    std::ostringstream oss;
    for (const int num : seq) oss << num;
    return oss.str();
}

// 39: /problems/combination-sum/
auto Leetcode::combination_sum(
    const std::vector<int>& candidates, const int target
) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    std::function<void(int, int)> backtrack = [&](const int nxt, const int r) {
        if (r == 0) {
            res.push_back(path);
            return;
        }
        if (nxt == candidates.size()) return;
        int i = 0;
        while (r - i * candidates[nxt] >= 0) {
            for (int j = 0; j < i; ++j) path.push_back(candidates[nxt]);
            backtrack(nxt + 1, r - i * candidates[nxt]);
            for (int j = 0; j < i; ++j) path.pop_back();
            i++;
        }
    };
    backtrack(0, target);
    return res;
}

// 40: /problems/combination-sum-ii/
auto Leetcode::combination_sum_2(
    const std::vector<int> &candidates, const int target
) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res;
    std::vector<int> current;
    std::vector<int> sorted_candidates = candidates;
    std::sort(sorted_candidates.begin(), sorted_candidates.end());
    std::function<void(int, int)> backtrack = [&](const int start, const int remain) {
        if (remain == 0) {
            res.push_back(current);
            return;
        }
        for (int i = start; i < sorted_candidates.size(); i++) {
            if (i > start && sorted_candidates[i] == sorted_candidates[i - 1]) continue;
            if (sorted_candidates[i] > remain) break;
            current.push_back(sorted_candidates[i]);
            backtrack(i + 1, remain - sorted_candidates[i]);
            current.pop_back();
        }
    };
    backtrack(0, target);
    return res;
}

// 41: /problems/first-missing-positive/
auto Leetcode::first_missing_positive(const std::vector<int>& nums) -> int {
    std::vector<int> arr = nums;
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            std::swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n + 1;
}

// 42: /problems/trapping-rain-water/
auto Leetcode::trap(const std::vector<int>& height) -> int {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int left_max = 0, right_max = 0;
    int res = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) left_max = height[left];
            else res += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max) right_max = height[right];
            else res += right_max - height[right];
            right--;
        }
    }
    return res;
}

// 43: /problems/multiply-strings/
auto Leetcode::multiply(const std::string& num1, const std::string& num2) -> std::string {
    if (num1 == "0" || num2 == "0") return "0";
    const int m = static_cast<int>(num1.size());
    const int n = static_cast<int>(num2.size());
    std::vector res(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            const int product = (num1[i] - '0') * (num2[j] - '0');
            const int sum = product + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    std::string res_str;
    bool leading_zero = true;
    for (const int digit : res) {
        if (digit != 0) leading_zero = false;
        if (!leading_zero) res_str += static_cast<char>('0' + digit);
    }
    return res_str.empty() ? "0" : res_str;
}

// 44: /problems/wildcard-matching/
auto Leetcode::is_match_wildcard(const std::string& s, const std::string& p) -> bool {
    int s_idx = 0, p_idx = 0;
    int star_p = -1, star_s = -1;
    while (s_idx < static_cast<int>(s.size())) {
        if (p_idx < p.length() && (p[p_idx] == '?' || p[p_idx] == s[s_idx])) {
            s_idx++;
            p_idx++;
        }
        else if (p_idx < p.length() && p[p_idx] == '*') {
            star_p = p_idx++;
            star_s = s_idx;
        }
        else if (star_p != -1) {
            p_idx = star_p + 1;
            s_idx = ++star_s;
        }
        else return false;
    }
    while (p_idx < p.length() && p[p_idx] == '*') p_idx++;
    return p_idx == p.length();
}

// 45: /problems/jump-game-ii/
auto Leetcode::jump(const std::vector<int>& nums) -> int {
    int jumps = 0, current_end = 0, farthest = 0;
    for (int i = 0; i < static_cast<int>(nums.size()) - 1; i++) {
        farthest = std::max(farthest, i + nums[i]);
        if (i == current_end) {
            jumps++;
            current_end = farthest;
        }
    }
    return jumps;
}

// 46: /problems/permutations/
auto Leetcode::permute(std::vector<int>& nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res;
    backtrack_permute(nums, 0, res);
    return res;
}

// 47: /problems/permutations-ii/
auto Leetcode::permute_unique(std::vector<int> &nums) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res;
    backtrack_permute_unique(nums, 0, res);
    return res;
}

// 48: /problems/rotate-image/
auto Leetcode::rotate(std::vector<std::vector<int>>& matrix) -> void {
    const int n = static_cast<int>(matrix.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

// 49: /problems/group-anagrams/
auto Leetcode::group_anagrams(const std::vector<std::string>& strs) -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> anagram_groups;
    for (const std::string &str : strs) {
        std::string key = str;
        std::sort(key.begin(), key.end());
        anagram_groups[key].push_back(str);
    }
    std::vector<std::vector<std::string>> res;
    res.reserve(anagram_groups.size());
    for (const auto &[key, value] : anagram_groups) {
        res.push_back(value);
    }
    return res;
}

// 50: /problems/powx-n/
auto Leetcode::my_pow(const double base_value, const int exponent) -> double {
    if (exponent == 0) return 1;
    double base = base_value;
    long long exp = exponent;
    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }
    double res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

// 51: /problems/n-queens/
auto Leetcode::solve_n_queens(const int n) -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> res;
    std::vector queens(n, -1);
    std::function<void(int, int, int, int)> backtrack =
        [&](const int row, const int cols, const int diag1, const int diag2) {
        if (row == n) {
            std::vector board(n, std::string(n, '.'));
            for (int i = 0; i < n; ++i) {
                board[i][queens[i]] = 'Q';
            }
            res.push_back(std::move(board));
            return;
        }
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            const int pos = available & -available;
            available ^= pos;
            const int col = __builtin_ctz(pos);
            queens[row] = col;
            backtrack(row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
        }
    };
    backtrack(0, 0, 0, 0);
    return res;
}

// 52: /problems/n-queens-ii/
auto Leetcode::total_n_queens(const int n) -> int {
    int count = 0;
    std::function<void(int, int, int, int)> backtrack =
        [&](const int row, const int cols, const int diag1, const int diag2) {
        if (row == n) {
            count++;
            return;
        }
        int available = (1 << n) - 1 & ~(cols | diag1 | diag2);
        while (available) {
            const int pos = available & -available;
            available ^= pos;
            backtrack(row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
        }
    };
    backtrack(0, 0, 0, 0);
    return count;
}

// 53: /problems/maximum-subarray/
auto Leetcode::max_sub_array(const std::vector<int>& nums) -> int {
    int current_max = nums[0], global_max = nums[0];
    for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
        if (current_max > 0) current_max += nums[i];
        else current_max = nums[i];
        if (current_max > global_max) global_max = current_max;
    }
    return global_max;
}