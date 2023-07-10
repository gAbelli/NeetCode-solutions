#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Priority {
  public:
    int timestamp;
    int quantity;
    Priority(int timestamp, int quantity)
        : timestamp(timestamp), quantity(quantity) {}
};

class Solution {
  public:
    int leastInterval(std::vector<char> &tasks, int n) {
        auto less = [&](Priority p1, Priority p2) {
            if (p1.timestamp > p2.timestamp) {
                return true;
            }
            if (p1.timestamp < p2.timestamp) {
                return false;
            }
            return p1.quantity < p2.quantity;
        };

        std::priority_queue<Priority, std::vector<Priority>, decltype(less)>
            queue(less);

        std::unordered_map<char, int> count;
        for (char c : tasks) {
            count[c]++;
        }

        for (const auto &pair : count) {
            queue.push(Priority(0, pair.second));
        }

        int time = 0;
        while (!queue.empty()) {
            Priority p = queue.top();
            if (p.timestamp <= time) {
                queue.pop();
                if (p.quantity > 1) {
                    queue.push(Priority(time + n, p.quantity - 1));
                }
            }
            time++;
        }

        return time;
    }
};
