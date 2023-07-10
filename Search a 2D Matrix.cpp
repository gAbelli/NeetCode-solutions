#include <iostream>
#include <vector>

class Solution {
  private:
    int get(std::vector<std::vector<int>> &matrix, int n) {
        return matrix[n / matrix[0].size()][n % matrix[0].size()];
    }

  public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int elem = get(matrix, mid);
            if (elem == target) {
                return true;
            }
            if (elem > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
