#include <iostream>
#include <vector>

class Solution {
  public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        bool zeroFirstRow = false;
        bool zeroFirstColumn = false;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for (int j = 0; j < columns; j++) {
            if (matrix[0][j] == 0) {
                zeroFirstRow = true;
            }
        }
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                zeroFirstColumn = true;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        for (int j = 1; j < columns; j++) {
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        for (int j = 1; j < columns; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < columns; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zeroFirstColumn) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
        if (zeroFirstRow) {
            for (int j = 0; j < columns; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
