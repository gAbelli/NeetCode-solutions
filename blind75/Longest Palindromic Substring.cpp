#include <iostream>

class Solution {
  public:
    std::string longestPalindrome(std::string s) {
        int best_i = 0;
        int best_len = 0;
        int n = s.size();

        // even
        for (int k = 0; k < n; ++k) {
            int i = k;
            int j = k + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                int len = j - i + 1;
                if (len > best_len) {
                    best_i = i;
                    best_len = len;
                }
                i--;
                j++;
            }
        }

        // odd
        for (int k = 0; k < n; ++k) {
            int i = k;
            int j = k;
            while (i >= 0 && j < n && s[i] == s[j]) {
                int len = j - i + 1;
                if (len > best_len) {
                    best_i = i;
                    best_len = len;
                }
                i--;
                j++;
            }
        }

        return s.substr(best_i, best_len);
    }
};
