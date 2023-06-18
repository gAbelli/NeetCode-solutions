#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    bool helper(std::string &s, std::vector<std::string> &wordDict, int index,
                std::vector<bool> &memo) {
        if (index == s.size()) {
            return true;
        }
        if (memo[index]) {
            return true;
        }
        for (const std::string &word : wordDict) {
            if (s.substr(index, word.size()) == word) {
                if (helper(s, wordDict, index + word.size(), memo)) {
                    memo[index] = true;
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        std::vector<bool> memo(s.size(), false);
        return helper(s, wordDict, 0, memo);
    }
};
