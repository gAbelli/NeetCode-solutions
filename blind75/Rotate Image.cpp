#include <iostream>
#include <vector>

class Solution {
  public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                std::swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};
