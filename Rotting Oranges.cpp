#include <climits>
#include <iostream>
#include <vector>

class Solution {
  public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(grid, i, j, 0);
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == INT_MAX) {
                    return -1;
                }
                res = std::max(res, grid[i][j] - 2);
            }
        }

        return res;
    }

    void dfs(std::vector<std::vector<int>> &grid, int i, int j, int depth) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = INT_MAX;
        }
        if (grid[i][j] <= 2 + depth && depth != 0) {
            return;
        }

        grid[i][j] = 2 + depth;

        dfs(grid, i + 1, j, depth + 1);
        dfs(grid, i - 1, j, depth + 1);
        dfs(grid, i, j + 1, depth + 1);
        dfs(grid, i, j - 1, depth + 1);
    }
};
