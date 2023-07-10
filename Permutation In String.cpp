#include <iostream>
#include <unordered_map>

class Solution {
  public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::unordered_map<char, int> count;
        for (char c : s1) {
            count[c]++;
        }

        for (int i = 0; i < s1.size(); ++i) {
            count[s2[i]]--;
        }
        bool valid = true;
        for (const auto &pair : count) {
            if (pair.second != 0) {
                valid = false;
            }
        }
        if (valid) {
            return true;
        }

        for (int i = s1.size(); i < s2.size(); ++i) {
            count[s2[i - s1.size()]]++;
            count[s2[i]]--;

            bool valid = true;
            for (const auto &pair : count) {
                if (pair.second != 0) {
                    valid = false;
                }
            }
            if (valid) {
                return true;
            }
        }

        return false;
    }
};
