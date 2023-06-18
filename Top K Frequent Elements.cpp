#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> count;
        for (int x : nums) {
            if (count.count(x)) {
                count[x]++;
            } else {
                count[x] = 1;
            }
        }

        std::vector<std::pair<int, int>> val_and_count;
        for (const auto &pair : count) {
            val_and_count.push_back(pair);
        }

        auto cmp = [](const auto &left, const auto &right) {
            return std::get<1>(left) > std::get<1>(right);
        };
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(cmp)>
            top_k_queue(cmp);

        for (const auto &pair : val_and_count) {
            if (top_k_queue.size() < k) {
                top_k_queue.push(pair);
            } else {
                std::pair<int, int> lowest_pair = top_k_queue.top();
                if (lowest_pair.second < pair.second) {
                    top_k_queue.pop();
                    top_k_queue.push(pair);
                }
            }
        }

        std::vector<int> res;
        res.reserve(k);
        while (!top_k_queue.empty()) {
            int n = top_k_queue.top().first;
            res.push_back(n);
            top_k_queue.pop();
        }

        return res;
    }
};
