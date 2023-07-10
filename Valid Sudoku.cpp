#include <iostream>
#include <vector>

class Solution {
  public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        bool found[9] = {0};

        // rows
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (found[board[i][j] - '1']) {
                        return false;
                    } else {
                        found[board[i][j] - '1'] = true;
                    }
                }
            }
            std::fill(found, found + 9, false);
        }

        // columns
        for (int j = 0; j < 9; ++j) {
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (found[board[i][j] - '1']) {
                        return false;
                    } else {
                        found[board[i][j] - '1'] = true;
                    }
                }
            }
            std::fill(found, found + 9, false);
        }

        // blocks
        for (int start_i = 0; start_i < 9; start_i += 3) {
            for (int start_j = 0; start_j < 9; start_j += 3) {
                for (int i = start_i; i < start_i + 3; ++i) {
                    for (int j = start_j; j < start_j + 3; ++j) {
                        if (board[i][j] != '.') {
                            if (found[board[i][j] - '1']) {
                                return false;
                            } else {
                                found[board[i][j] - '1'] = true;
                            }
                        }
                    }
                }
                std::fill(found, found + 9, false);
            }
        }

        return true;
    }
};
