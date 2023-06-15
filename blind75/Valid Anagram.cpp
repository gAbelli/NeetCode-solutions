#include <iostream>

class Solution {
  public:
    int count[128];

    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::fill(count, count + 128, 0);
        for (char c : s) {
            count[c]++;
        }
        for (char c : t) {
            if (!count[c]) {
                return false;
            }
            count[c]--;
        }
        return true;
    }
};
