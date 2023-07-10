#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

        for (int n : nums) {
            if (queue.size() < k) {
                queue.push(n);
            } else {
                int top = queue.top();
                if (n > top) {
                    queue.pop();
                    queue.push(n);
                }
            }
        }

        return queue.top();
    }
};
