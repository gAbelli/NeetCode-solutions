#include <iostream>
#include <vector>

class Solution {
  public:
    int maxProduct(std::vector<int> &nums) {
        int current_max = nums[0];
        int current_min = nums[0];
        int global_max = nums[0];
        for (int k = 1; k < nums.size(); ++k) {
            int backup_current_max = current_max;
            current_max = std::max(
                {current_max * nums[k], current_min * nums[k], nums[k]});
            current_min = std::min(
                {backup_current_max * nums[k], current_min * nums[k], nums[k]});
            global_max = std::max(global_max, current_max);
        }
        return global_max;
    }
};
