#include <iostream>

class Solution {
  public:
    int helper(std::string &text1, std::string &text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        int res = std::max(helper(text1, text2, i + 1, j),
                           helper(text1, text2, i, j + 1));
        if (text1[i] == text2[j]) {
            res = std::max(res, 1 + helper(text1, text2, i + 1, j + 1));
        }
        return res;
    }

    int longestCommonSubsequence(std::string text1, std::string text2) {
        return helper(text1, text2, 0, 0);
    }
};
