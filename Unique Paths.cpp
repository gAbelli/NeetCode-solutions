#include <iostream>

class Solution {
  public:
    int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }
        m--;
        n--;
        unsigned long long res = 1;
        // (m + n)! / (m! * n!)
        // (m+n) * ... * (n+1) / n!
        for (int i = n; i > 0; --i) {
            res *= (m + i);
        }
        for (int i = 1; i <= n; ++i) {
            res /= i;
        }
        return res;
    }
};
