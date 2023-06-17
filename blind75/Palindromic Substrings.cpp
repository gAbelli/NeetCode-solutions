#include <iostream>

class Solution {
  public:
    int countSubstrings(std::string s) {
        int n = s.size();
        int res = 0;

        // even
        for (int k = 0; k < n; ++k) {
            int i = k;
            int j = k + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                res++;
                i--;
                j++;
            }
        }

        // odd
        for (int k = 0; k < n; ++k) {
            int i = k;
            int j = k;
            while (i >= 0 && j < n && s[i] == s[j]) {
                res++;
                i--;
                j++;
            }
        }

        return res;
    }
};
