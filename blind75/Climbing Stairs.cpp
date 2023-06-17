#include <iostream>

class Solution {
  public:
    int memo[45] = {0};

    int climbStairs(int n) {
        if (memo[0] != 0) {
            return memo[n - 1];
        }
        memo[0] = 1;
        memo[1] = 2;
        for (int i = 2; i < 45; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n - 1];
    }
};
