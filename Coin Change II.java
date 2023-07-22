import java.util.ArrayList;
import java.util.List;

class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;

        for (int x : coins) {
            List<Integer[]> toAdd = new ArrayList<>();

            for (int i = 0; i <= amount; ++i) {
                if (dp[i] != 0) {
                    int y = x;
                    while (y + i <= amount) {
                        toAdd.add(new Integer[] {y + i, dp[i]});
                        y += x;
                    }
                }
            }

            for (Integer[] pair : toAdd) {
                dp[pair[0]] += pair[1];
            }
        }

        return dp[amount];
    }

    public static void main(String[] args) {
        System.out.println(new Solution().change(5000, new int[] {1, 2}));
    }
}
