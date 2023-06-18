#include <iostream>
#include <vector>

class Solution {
  public:
    bool dfs(std::vector<std::vector<char>> &board, std::string &word,
             int start_i, int start_j, int index) {
        if (index == word.size()) {
            return true;
        }
        if (start_i < 0 || start_i >= board.size() || start_j < 0 ||
            start_j >= board[0].size() ||
            board[start_i][start_j] != word[index]) {
            return false;
        }
        char c = board[start_i][start_j];
        board[start_i][start_j] = '#';

        if (dfs(board, word, start_i + 1, start_j, index + 1))
            return true;
        if (dfs(board, word, start_i - 1, start_j, index + 1))
            return true;
        if (dfs(board, word, start_i, start_j + 1, index + 1))
            return true;
        if (dfs(board, word, start_i, start_j - 1, index + 1))
            return true;

        board[start_i][start_j] = c;
        return false;
    }

    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
