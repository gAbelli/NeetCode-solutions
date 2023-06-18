#include <iostream>
#include <vector>

class Solution {
  public:
    int helper(std::vector<int> &coins, int amount, int index, int n_coins) {
        if (amount == 0) {
            return n_coins;
        }
        if (index >= coins.size()) {
            return -1;
        }
        int coin = coins[index];
        int max_coins = amount / coin;
        while (max_coins >= 0) {
            int res = helper(coins, amount - max_coins * coin, index + 1,
                             n_coins + max_coins);
            if (res != -1) {
                return res;
            }
            max_coins--;
        }
        return -1;
    }

    int coinChange(std::vector<int> &coins, int amount) {
        std::sort(coins.begin(), coins.end(), std::greater<int>());
        return helper(coins, amount, 0, 0);
    }
};
