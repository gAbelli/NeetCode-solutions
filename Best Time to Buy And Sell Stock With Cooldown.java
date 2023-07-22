class Solution {
    private int[] memo;

    public int maxProfit(int[] prices) {
        memo = new int[prices.length];
        for (int i = 0; i < prices.length; ++i) {
            memo[i] = -1;
        }
        return compute(prices, 0);
    }

    private int compute(int[] prices, int i) {
        if (i >= prices.length) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }

        int profit = compute(prices, i + 1);

        for (int j = i + 1; j < prices.length; ++j) {
            profit = Math.max(prices[j] - prices[i] + compute(prices, j + 2),
                              profit);
        }

        memo[i] = profit;

        return profit;
    }
}
