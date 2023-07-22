#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                  int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        dfs(candidates, target, res, cur, 0, 0);

        return res;
    }

    void dfs(std::vector<int> &candidates, int target,
             std::vector<std::vector<int>> &res, std::vector<int> &cur, int sum,
             int index) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            std::cout << index << ' ' << i << std::endl;
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            dfs(candidates, target, res, cur, sum + candidates[i], i + 1);
            cur.pop_back();
        }
    }
};
