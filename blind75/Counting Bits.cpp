#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> countBits(int n) {
        std::vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};
