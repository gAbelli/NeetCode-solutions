class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }

        boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
        dp[0][0] = true;

        // populate first row
        for (int j = 1; j <= s2.length(); ++j) {
            if (s2.charAt(j - 1) == s3.charAt(j - 1)) {
                dp[0][j] = true;
            } else {
                break;
            }
        }

        // populate first col
        for (int i = 1; i <= s1.length(); ++i) {
            if (s1.charAt(i - 1) == s3.charAt(i - 1)) {
                dp[i][0] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i <= s1.length(); ++i) {
            for (int j = 1; j <= s2.length(); ++j) {
                if ((s1.charAt(i - 1) == s3.charAt(i + j - 1) &&
                     dp[i - 1][j]) ||
                    (s2.charAt(j - 1) == s3.charAt(i + j - 1) &&
                     dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[s1.length()][s2.length()];
    }
}
