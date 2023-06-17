#include <iostream>
#include <vector>

class Solution {
  public:
    bool dfs(std::vector<std::vector<char>> &grid, int start_i, int start_j) {
        if (start_i < 0 || start_i >= grid.size() || start_j < 0 ||
            start_j >= grid[0].size() || grid[start_i][start_j] != '1') {
            return false;
        }
        grid[start_i][start_j] = '0';
        dfs(grid, start_i + 1, start_j);
        dfs(grid, start_i - 1, start_j);
        dfs(grid, start_i, start_j + 1);
        dfs(grid, start_i, start_j - 1);

        return true;
    }

    int numIslands(std::vector<std::vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (dfs(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
