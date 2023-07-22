#include <iostream>
#include <vector>

class Solution {
  public:
    void solve(std::vector<std::vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool ok = canReachBorder(board, i, j);
                if (ok) {
                    set(board, i, j, 'Y');
                } else {
                    set(board, i, j, 'N');
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
                if (board[i][j] == 'N') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    bool canReachBorder(std::vector<std::vector<char>> &board, int i, int j) {
        if (board[i][j] != 'O') {
            return false;
        }
        board[i][j] = 'V';

        if ((i == 0 || i == board.size() - 1 || j == 0 ||
             j == board[0].size() - 1)) {
            return true;
        }

        return (canReachBorder(board, i + 1, j) ||
                canReachBorder(board, i - 1, j) ||
                canReachBorder(board, i, j + 1) ||
                canReachBorder(board, i, j - 1));
    }

    void set(std::vector<std::vector<char>> &board, int i, int j, char c) {
        if ((i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) ||
            board[i][j] != 'V') {
            return;
        }
        board[i][j] = c;

        set(board, i + 1, j, c);
        set(board, i - 1, j, c);
        set(board, i, j + 1, c);
        set(board, i, j - 1, c);
    }
};
