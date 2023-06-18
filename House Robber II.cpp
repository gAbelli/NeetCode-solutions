#include <iostream>
#include <vector>

class Solution {
  public:
    int helper(std::vector<int> &nums, std::vector<int> &memo, int start,
               int end) {
        if (start > end) {
            return 0;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        int res = std::max(nums[start] + helper(nums, memo, start + 2, end),
                           helper(nums, memo, start + 1, end));
        memo[start] = res;
        return res;
    }

    int rob(std::vector<int> &nums) {
        std::vector<int> memo(nums.size(), -1);
        int res_1 = helper(nums, memo, 0, nums.size() - 2);
        std::fill(memo.begin(), memo.end(), -1);
        int res_2 = helper(nums, memo, 1, nums.size() - 1);
        return std::max(res_1, res_2);
    }
};
