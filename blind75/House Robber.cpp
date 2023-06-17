#include <iostream>
#include <vector>

class Solution {
  public:
    int helper(std::vector<int> &nums, std::vector<int> &memo, int start) {
        if (start >= nums.size()) {
            return 0;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        int res = std::max(nums[start] + helper(nums, memo, start + 2),
                           helper(nums, memo, start + 1));
        memo[start] = res;
        return res;
    }

    int rob(std::vector<int> &nums) {
        std::vector<int> memo(nums.size(), -1);
        return helper(nums, memo, 0);
    }
};
