#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinIndex(std::vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int get(std::vector<int> &nums, int rotation, int i) {
        return nums[(rotation + i) % nums.size()];
    }

    int search(std::vector<int> &nums, int target) {
        int rotation = findMinIndex(nums);
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (get(nums, rotation, mid) == target) {
                return (rotation + mid) % n;
            }
            if (get(nums, rotation, mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (get(nums, rotation, left) == target) {
            return (left + rotation) % n;
        }
        return -1;
    }
};
