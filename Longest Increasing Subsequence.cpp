#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
