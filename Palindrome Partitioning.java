import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean[][] dp;

    public List<List<String>> partition(String s) {
        this.createDp(s);
        List<List<String>> res = new ArrayList<>();
        List<String> cur = new ArrayList<>();
        dfs(s, res, cur, 0);

        return res;
    }

    private void createDp(String s) {
        this.dp = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); ++i) {
            this.dp[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            this.dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
        }

        for (int offset = 2; offset < s.length(); ++offset) {
            for (int i = 0; i < s.length() - offset; ++i) {
                this.dp[i][i + offset] = s.charAt(i) == s.charAt(i + offset) &&
                                         this.dp[i + 1][i + offset - 1];
            }
        }
    }

    private void dfs(String s, List<List<String>> res, List<String> cur,
                     int index) {
        if (index == s.length()) {
            res.add(new ArrayList<>(cur));
            return;
        }

        for (int i = index; i < s.length(); ++i) {
            if (this.isPalindrome(s, index, i)) {
                cur.add(s.substring(index, i + 1));
                dfs(s, res, cur, i + 1);
                cur.remove(cur.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int left, int right) {
        return dp[left][right];
    }
}
