#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> degree(numCourses, 0);
        for (const auto &pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
            degree[pair[0]]++;
        }

        std::queue<int> queue;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                queue.push(i);
            }
        }

        while (!queue.empty()) {
            int course = queue.front();
            queue.pop();
            numCourses--;
            for (int neighbor : adj[course]) {
                degree[neighbor]--;
                if (degree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        return numCourses == 0;
    }
};
