#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<int> cur;
        std::vector<std::vector<int>> res;
        helper(nums, cur, res, 0, nums.size());
        return res;
    }

    void helper(std::vector<int> &nums, std::vector<int> &cur,
                std::vector<std::vector<int>> &res, int i, int n) {
        if (i == n) {
            std::vector<int> curCopy = cur;
            res.push_back(curCopy);
            return;
        }

        helper(nums, cur, res, i + 1, n);

        cur.push_back(nums[i]);
        helper(nums, cur, res, i + 1, n);
        cur.pop_back();
    }
};
