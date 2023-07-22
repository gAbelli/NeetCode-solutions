import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int halfSum = sum / 2;

        boolean[] dp = new boolean[halfSum + 1];
        dp[0] = true;

        for (int x : nums) {
            List<Integer> toAdd = new ArrayList<>();

            for (int i = 0; i <= halfSum; ++i) {
                if (dp[i]) {
                    if (i + x == halfSum) {
                        return true;
                    }
                    if (i + x < halfSum) {
                        // dp[i + x] = true;
                        toAdd.add(i + x);
                    }
                }
            }

            for (int i : toAdd) {
                dp[i] = true;
            }
        }

        return false;
    }
}
