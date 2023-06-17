#include <iostream>
#include <unordered_set>
#include <vector>

class ConnectingGraph3 {
  public:
    int node_count;
    std::vector<std::vector<int>> adj;

    ConnectingGraph3(int n) { node_count = n; }
    void connect(int a, int b) {
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int query() {
        std::vector<bool> visited(node_count, false);
        int count = 0;
        for (int i = 0; i < node_count; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i, visited);
            }
        }
        return count;
    }

    void dfs(int start, std::vector<bool> &visited) {
        visited[start] = true;
        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
};
