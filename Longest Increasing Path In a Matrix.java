class Solution {
    private int[][] memo;

    public int longestIncreasingPath(int[][] matrix) {
        memo = new int[matrix.length][matrix[0].length];
        int maxDepth = 0;

        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                maxDepth = Math.max(maxDepth, dfs(matrix, i, j, -1));
            }
        }

        return maxDepth;
    }

    private int dfs(int[][] matrix, int i, int j, int prev) {
        if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length ||
            matrix[i][j] == -1 || matrix[i][j] <= prev) {
            return 0;
        }
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int backup = matrix[i][j];
        matrix[i][j] = -1;

        int maxDepth = 0;
        maxDepth = Math.max(maxDepth, 1 + dfs(matrix, i + 1, j, backup));
        maxDepth = Math.max(maxDepth, 1 + dfs(matrix, i - 1, j, backup));
        maxDepth = Math.max(maxDepth, 1 + dfs(matrix, i, j + 1, backup));
        maxDepth = Math.max(maxDepth, 1 + dfs(matrix, i, j - 1, backup));

        matrix[i][j] = backup;
        memo[i][j] = maxDepth;

        return maxDepth;
    }
}
