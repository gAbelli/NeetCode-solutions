#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    insert(std::vector<std::vector<int>> &intervals,
           std::vector<int> &newInterval) {
        std::vector<std::vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
