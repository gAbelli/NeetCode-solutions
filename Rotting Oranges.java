class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, m, n, 0);
                }
            }
        }

        int maxTime = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (grid[i][j] == 1) {
                    return -1;
                }
                if (grid[i][j] < 0) {
                    maxTime = Math.max(maxTime, -grid[i][j]);
                }
            }
        }

        return maxTime;
    }

    private void dfs(int[][] grid, int i, int j, int m, int n, int depth) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        } else if (grid[i][j] == 0) {
            return;
        } else if (grid[i][j] == 2 && depth != 0) {
            return;
        } else if (grid[i][j] == 1) {
            grid[i][j] = -depth;
        } else if (grid[i][j] < 0) {
            if (-grid[i][j] <= depth) {
                return;
            }
            grid[i][j] = -depth;
        }

        dfs(grid, i + 1, j, m, n, depth + 1);
        dfs(grid, i - 1, j, m, n, depth + 1);
        dfs(grid, i, j + 1, m, n, depth + 1);
        dfs(grid, i, j - 1, m, n, depth + 1);
    }
}
