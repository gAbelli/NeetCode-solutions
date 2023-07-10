#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            }
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};
