#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int diff = target - nums[i];
            if (pos.count(diff)) {
                return {pos[diff], i};
            }
            pos[nums[i]] = i;
        }
        return {-1, -1};
    }
};
