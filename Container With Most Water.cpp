#include <iostream>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;

        while (i < j) {
            res = std::max(res, (j - i) * std::min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};
