#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>>
    kClosest(std::vector<std::vector<int>> &points, int k) {
        auto less = [&](std::pair<int, int> p1, std::pair<int, int> p2) {
            return (p1.first * p1.first + p1.second * p1.second <
                    p2.first * p2.first + p2.second * p2.second);
        };

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(less)>
            queue(less);

        for (const auto &point : points) {
            if (queue.size() < k) {
                queue.push({point[0], point[1]});
            } else {
                std::pair<int, int> top = queue.top();
                if (less({point[0], point[1]}, top)) {
                    queue.pop();
                    queue.push({point[0], point[1]});
                }
            }
        }

        std::vector<std::vector<int>> res;
        while (!queue.empty()) {
            std::pair<int, int> top = queue.top();
            res.push_back({top.first, top.second});
            queue.pop();
        }

        return res;
    }
};
