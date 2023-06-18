#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        int left = 0;
        std::vector<int> res;

        while (top <= bottom && left <= right) {
            // top
            {
                int i = top;
                for (int j = left; j <= right; ++j) {
                    res.push_back(matrix[i][j]);
                }
                top++;
            }
            // right
            {
                int j = right;
                for (int i = top; i <= bottom; ++i) {
                    res.push_back(matrix[i][j]);
                }
                right--;
            }
            // bottom
            if (top <= bottom) {
                int i = bottom;
                for (int j = right; j >= left; --j) {
                    res.push_back(matrix[i][j]);
                }
                bottom--;
            }
            // left
            if (left <= right) {
                int j = left;
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][j]);
                }
                left++;
            }
        }
        return res;
    }
};
