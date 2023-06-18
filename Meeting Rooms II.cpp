#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int res = 0;

        for (int i = 0; i < intervals.size(); ++i) {
            while (!pq.empty() && intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            res = std::max(res, (int)pq.size());
        }

        return res;
    }
};
