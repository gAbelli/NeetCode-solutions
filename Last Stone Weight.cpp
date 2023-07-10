#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    int lastStoneWeight(std::vector<int> &stones) {
        std::priority_queue<int> queue;
        for (int stone : stones) {
            queue.push(stone);
        }
        while (queue.size() > 1) {
            int heaviest = queue.top();
            queue.pop();
            int secondHeaviest = queue.top();
            queue.pop();
            if (heaviest != secondHeaviest) {
                queue.push(heaviest - secondHeaviest);
            }
        }
        if (queue.empty()) {
            return 0;
        }
        return queue.top();
    }
};
