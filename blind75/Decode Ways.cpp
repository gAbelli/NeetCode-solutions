#include <iostream>

class Solution {
  public:
    int numDecodings(std::string s) {
        if (s.size() == 1) {
            return s[0] == '0' ? 0 : 1;
        }
        int n = s.size();
        n--;
        int next = s[n] == '0' ? 0 : 1;
        n--;
        int cur = next;
        if (s[n] == '0') {
            cur = 0;
        } else if (s[n] == '1') {
            cur++;
        } else if (s[n] == '2' && s[n + 1] - '0' <= 6) {
            cur++;
        }
        while (n > 0) {
            n--;
            int prev = cur;
            if (s[n] == '0') {
                prev = 0;
            } else if (s[n] == '1') {
                prev = cur + next;
            } else if (s[n] == '2' && s[n + 1] - '0' <= 6) {
                prev = cur + next;
            }
            next = cur;
            cur = prev;
        }
        return cur;
    }
};
