#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> count;
        std::priority_queue<int> queue;
        std::vector<int> res;

        for (int i = 0; i < k; ++i) {
            count[nums[i]]++;
            queue.push(nums[i]);
        }
        res.push_back(queue.top());

        for (int i = k; i < nums.size(); ++i) {
            count[nums[i - k]]--;
            count[nums[i]]++;
            queue.push(nums[i]);
            while (count[queue.top()] == 0) {
                queue.pop();
            }
            res.push_back(queue.top());
        }

        return res;
    }
};
