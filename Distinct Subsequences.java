class Solution {
    public int numDistinct(String s, String t) {
        if (t.length() > s.length()) {
            return 0;
        }

        int[] dp = new int[t.length()];

        if (s.charAt(s.length() - 1) == t.charAt(t.length() - 1)) {
            dp[t.length() - 1] = 1;
        }

        for (int i = s.length() - 2; i >= 0; --i) {
            for (int j = 0; j < t.length(); ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    if (j + 1 < t.length()) {
                        dp[j] += dp[j + 1];
                    } else {
                        dp[j] += 1;
                    }
                }
            }
        }

        return dp[0];
    }
}

// int[][] dp = new int[s.length()][t.length()];
//
// if (s.charAt(s.length() - 1) == t.charAt(t.length() - 1)) {
// dp[s.length() - 1][t.length() - 1] = 1;
// }
//
// for (int j = t.length() - 1; j >= 0; --j) {
// for (int i = s.length() - 2; i >= 0; --i) {
// 	dp[i][j] = dp[i + 1][j];
// 	if (s.charAt(i) == t.charAt(j)) {
// 		if (j + 1 < t.length()) {
// 			dp[i][j] += dp[i + 1][j + 1];
// 		} else {
// 			dp[i][j] += 1;
// 		}
// 	}
// }
// }
//
// return dp[0][0];
