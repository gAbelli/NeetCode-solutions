#include <climits>
#include <iostream>
#include <vector>

// (firstIndex + 1) + (secondIndex + 1) = ceil(( n1 + n2 )/2)
#define secondIndex(firstIndex) (half - firstIndex - 2)

class Solution {
  public:
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        bool even = (n1 + n2) % 2 == 0;
        int half = even ? (n1 + n2) / 2 : (n1 + n2) / 2 + 1;

        if (n1 == 0) {
            if (!even) {
                return nums2[half - 1];
            }
            return (double)(nums2[half - 1] + nums2[half]) / 2;
        }
        if (nums2[half - 1] <= nums1[0]) {
            if (!even) {
                return nums2[half - 1];
            }
            int min = nums1[0];
            if (half < nums2.size()) {
                min = std::min(min, nums2[half]);
            }
            return (double)(nums2[half - 1] + min) / 2;
        }
        if (half - 1 < nums1.size() && nums1[half - 1] <= nums2[0]) {
            if (!even) {
                return nums1[half - 1];
            }
            int min = nums2[0];
            if (half < nums1.size()) {
                min = std::min(min, nums1[half]);
            }
            return (double)(nums1[half - 1] + min) / 2;
        }

        int a = 0;
        int b = nums1.size() - 1;
        while (true) {
            int firstIndex = (a + b) / 2;
            int secondIndex = secondIndex(firstIndex);
            int res = isValid(firstIndex, secondIndex, nums1, nums2);
            if (res == 0) {
                return median(firstIndex, secondIndex, nums1, nums2);
            }
            if (res == 1) {
                b = firstIndex - 1;
            } else {
                a = firstIndex + 1;
            }
        }

        return 0;
    }

  private:
    int isValid(int firstIndex, int secondIndex, std::vector<int> &nums1,
                std::vector<int> &nums2) {
        if (secondIndex < nums2.size() - 1 &&
            nums1[firstIndex] > nums2[secondIndex + 1]) {
            return 1;
        }
        if (firstIndex < nums1.size() - 1 &&
            nums2[secondIndex] > nums1[firstIndex + 1]) {
            return -1;
        }
        return 0;
    }

    double median(int firstIndex, int secondIndex, std::vector<int> &nums1,
                  std::vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        bool even = (n1 + n2) % 2 == 0;

        int maxLeft = std::max(nums1[firstIndex], nums2[secondIndex]);
        if (!even) {
            return maxLeft;
        }
        int minRight = INT_MAX;
        if (firstIndex < nums1.size() - 1 && nums1[firstIndex + 1] < minRight) {
            minRight = nums1[firstIndex + 1];
        }
        if (secondIndex < nums2.size() - 1 &&
            nums2[secondIndex + 1] < minRight) {
            minRight = nums2[secondIndex + 1];
        }

        return (double)(maxLeft + minRight) / 2;
    }
};
