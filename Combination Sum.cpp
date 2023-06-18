#include <iostream>
#include <vector>

class Solution {
  public:
    void helper(std::vector<int> &candidates,
                std::vector<std::vector<int>> &res, std::vector<int> &buffer,
                int target, int start) {
        if (target == 0) {
            std::vector<int> buffer_copy = buffer;
            res.push_back(buffer_copy);
            return;
        }
        if (start == candidates.size()) {
            return;
        }
        int val = 0;
        while (val <= target) {
            helper(candidates, res, buffer, target - val, start + 1);
            val += candidates[start];
            buffer.push_back(candidates[start]);
        }
        while (val > 0) {
            buffer.pop_back();
            val -= candidates[start];
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                                 int target) {
        std::sort(candidates.begin(), candidates.end(), std::greater<int>());
        std::vector<std::vector<int>> res;
        std::vector<int> buffer;
        helper(candidates, res, buffer, target, 0);
        return res;
    }
};
