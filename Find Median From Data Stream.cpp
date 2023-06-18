#include <iostream>
#include <queue>

class MedianFinder {
  public:
    std::priority_queue<int> left_queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_queue;

    MedianFinder() {}

    void addNum(int num) {
        int min_right = INT_MAX;
        if (!right_queue.empty()) {
            min_right = right_queue.top();
        }
        if (num <= min_right) {
            left_queue.push(num);
        } else {
            right_queue.push(num);
        }
        if (left_queue.size() > right_queue.size() + 1) {
            right_queue.push(left_queue.top());
            left_queue.pop();
        } else if (right_queue.size() > left_queue.size()) {
            left_queue.push(right_queue.top());
            right_queue.pop();
        }
    }

    double findMedian() {
        if (left_queue.size() != right_queue.size()) {
            return left_queue.top();
        } else {
            return ((double)(left_queue.top() + right_queue.top())) / 2.0;
        }
    }
};
