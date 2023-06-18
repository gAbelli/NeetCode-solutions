#include <iostream>
#include <unordered_set>
#include <vector>

class Trie {
  public:
    Trie *children[26] = {nullptr};
    bool ok = false;

    Trie() {}

    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    void insert(std::string word) {
        Trie *cur = this;
        for (char c : word) {
            std::cout << c << std::endl;
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new Trie;
            }
            cur = cur->children[c - 'a'];
        }
        cur->ok = true;
    }

    bool search(std::string word) {
        Trie *cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->ok;
    }

    bool startsWith(std::string prefix) {
        Trie *cur = this;
        for (char c : prefix) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};

class Solution {
  public:
    void dfs(std::vector<std::vector<char>> &board,
             std::vector<std::string> &words,
             std::unordered_set<std::string> &res, std::string &buffer,
             Trie &dictionary, int start_i, int start_j) {
        if (start_i < 0 || start_i >= board.size() || start_j < 0 ||
            start_j >= board[0].size()) {
            return;
        }
        char c = board[start_i][start_j];
        board[start_i][start_j] = '#';
        if (c == '#') {
            return;
        }
        buffer += c;
        if (dictionary.search(buffer)) {
            res.insert(buffer);
        }
        if (dictionary.startsWith(buffer)) {
            dfs(board, words, res, buffer, dictionary, start_i + 1, start_j);
            dfs(board, words, res, buffer, dictionary, start_i - 1, start_j);
            dfs(board, words, res, buffer, dictionary, start_i, start_j + 1);
            dfs(board, words, res, buffer, dictionary, start_i, start_j - 1);
        }

        buffer = buffer.substr(0, buffer.size() - 1);
        board[start_i][start_j] = c;
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        Trie dictionary;
        for (auto &word : words) {
            dictionary.insert(word);
        }
        std::unordered_set<std::string> res_set;
        std::string buffer = "";
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                dfs(board, words, res_set, buffer, dictionary, i, j);
            }
        }
        std::vector<std::string> res;
        for (const auto &s : res_set) {
            res.push_back(s);
        }
        return res;
    }
};
