#include <iostream>
#include <vector>

class Solution {
  public:
    int maxProfit(std::vector<int> &prices) {
        int left = 0;
        int right = 0;
        int best_profit = 0;
        int n = prices.size();

        for (; right < n; ++right) {
            int profit = prices[right] - prices[left];
            if (profit < 0) {
                left = right;
            } else {
                if (profit > best_profit) {
                    best_profit = profit;
                }
            }
        }

        return best_profit;
    }
};
