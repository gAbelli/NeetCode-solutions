#include <iostream>
#include <vector>

class Solution {
  public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](std::vector<int> &l, std::vector<int> &r) {
                 return l[0] < r[0];
             });
        int res = 0;
        int i = 0;
        int j = 1;
        while (j < intervals.size()) {
            if (intervals[j][0] >= intervals[i][1]) {
                i = j;
            } else {
                res++;
                if (intervals[i][1] >= intervals[j][1]) {
                    i = j;
                }
            }
            j++;
        }
        return res;
    }
};
