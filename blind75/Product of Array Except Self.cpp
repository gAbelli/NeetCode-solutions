#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> res = nums;
        for (int i = 1; i < n; ++i) {
            nums[i] *= nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            res[i] *= res[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                res[i] = res[i + 1];
            } else if (i == n - 1) {
                res[i] = nums[i - 1];
            } else {
                res[i] = nums[i - 1] * res[i + 1];
            }
        }
        return res;
    }
};
