#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    merge(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [](std::vector<int> &l, std::vector<int> &r) {
                      return l[0] < r[0];
                  });
        int i = 0;
        int n = intervals.size();
        std::vector<std::vector<int>> res;
        while (i < n) {
            std::vector<int> current_interval = intervals[i];
            i++;
            while (i < n && intervals[i][0] <= current_interval[1]) {
                current_interval[1] =
                    std::max(current_interval[1], intervals[i][1]);
                i++;
            }
            res.push_back(current_interval);
        }
        return res;
    }
};
