#include <iostream>
#include <vector>

class Solution {
  public:
    int maxSubArray(std::vector<int> &nums) {
        int current_max = nums[0];
        int global_max = nums[0];
        for (int k = 1; k < nums.size(); ++k) {
            current_max = std::max(nums[k], nums[k] + current_max);
            global_max = std::max(global_max, current_max);
        }
        return global_max;
    }
};
