#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int search(int x, std::unordered_map<int, int> &best_from) {
        if (!best_from.count(x)) {
            return 0;
        }
        if (best_from[x]) {
            return best_from[x];
        }
        int res = 1 + search(x + 1, best_from);
        best_from[x] = res;
        return res;
    }

    int longestConsecutive(std::vector<int> &nums) {
        std::unordered_map<int, int> best_from;
        for (int x : nums) {
            best_from[x] = 0;
        }

        int res = 0;
        for (int x : nums) {
            res = std::max(res, search(x, best_from));
        }

        return res;
    }
};
