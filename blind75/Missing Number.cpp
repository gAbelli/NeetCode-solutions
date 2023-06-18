#include <iostream>
#include <numeric>
#include <vector>

class Solution {
  public:
    int missingNumber(std::vector<int> &nums) {
        long n = nums.size();
        return n * (n + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};
