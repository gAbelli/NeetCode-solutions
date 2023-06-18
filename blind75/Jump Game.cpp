#include <iostream>
#include <vector>

class Solution {
  public:
    bool canJump(std::vector<int> &nums) {
        int jump = 0;
        for (int k = 0; k < nums.size(); ++k) {
            jump--;
            jump = std::max(jump, nums[k]);
            if (jump == 0) {
                return false;
            }
        }
        return true;
    }
};
