#ifndef WORK_ZZZ_CPP_LEETCODE_H
#define WORK_ZZZ_CPP_LEETCODE_H

#include <vector>
#include <unordered_map>

class Leetcode {
public:
    Leetcode() = default;

    virtual ~Leetcode() = default;

    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

#endif
