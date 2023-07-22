#include <iostream>
#include <vector>

class Solution {
  public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                dfs(grid, count, i, j);
                res = std::max(res, count);
            }
        }
        return res;
    }

    void dfs(std::vector<std::vector<int>> &grid, int &count, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        count++;

        dfs(grid, count, i + 1, j);
        dfs(grid, count, i - 1, j);
        dfs(grid, count, i, j + 1);
        dfs(grid, count, i, j - 1);
    }
};
