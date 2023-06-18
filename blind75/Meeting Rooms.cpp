#include <iostream>
#include <vector>

class Interval {
  public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
  public:
    bool canAttendMeetings(std::vector<Interval> &intervals) {
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            }
        }
        return true;
    }
};
