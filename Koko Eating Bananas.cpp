#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
  public:
    int minEatingSpeed(std::vector<int> &piles, int h) {
        int maxBananasInAPile = 0;
        int totalBananas = 0;
        for (int n : piles) {
            totalBananas += n;
            if (n > maxBananasInAPile) {
                maxBananasInAPile = n;
            }
        }

        int left = std::ceil((double)totalBananas / (double)h);
        int right = maxBananasInAPile;
        while (left < right) {
            int k = (left + right) / 2;
            int hoursNeeded = 0;
            for (int pile : piles) {
                hoursNeeded += std::ceil((double)pile / (double)k);
            }
            if (hoursNeeded > h) {
                left = k + 1;
            } else {
                right = k;
            }
        }

        return left;
    }
};
