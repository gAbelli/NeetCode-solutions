import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        HashSet<Integer> columns = new HashSet<>();
        HashSet<Integer> forwardDiags = new HashSet<>();
        HashSet<Integer> backwardDiags = new HashSet<>();
        List<List<String>> res = new ArrayList<>();
        char[][] cur = new char[n][n];
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cur[row][col] = '.';
            }
        }

        dfs(n, columns, forwardDiags, backwardDiags, cur, res, 0);
        return res;
    }

    private void dfs(int n, HashSet<Integer> columns,
                     HashSet<Integer> forwardDiags,
                     HashSet<Integer> backwardDiags, char[][] cur,
                     List<List<String>> res, int row) {
        if (row == n) {
            List<String> board = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                board.add(new String(cur[i]));
            }
            res.add(board);
        }

        for (int col = 0; col < n; ++col) {
            if (columns.contains(col) || forwardDiags.contains(col - row) ||
                backwardDiags.contains(col + row)) {
                continue;
            }

            cur[row][col] = 'Q';
            columns.add(col);
            forwardDiags.add(col - row);
            backwardDiags.add(col + row);

            dfs(n, columns, forwardDiags, backwardDiags, cur, res, row + 1);

            columns.remove(col);
            forwardDiags.remove(col - row);
            backwardDiags.remove(col + row);
            cur[row][col] = '.';
        }
    }
}
