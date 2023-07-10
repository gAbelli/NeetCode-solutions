#include <iostream>
#include <unordered_map>

class Solution {
  public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> count;
        for (char c : t) {
            count[c]++;
        }
        int matchedChars = 0;
        int lowestLength = INT_MAX;
        int bestLeft = -1;
        int bestRight = -1;

        int left = 0;
        int right = 0;
        while (right < s.size()) {
            char c = s[right];
            count[c]--;
            if (count[c] >= 0) {
                matchedChars++;
            }
            if (matchedChars == t.size() && right - left + 1 <= lowestLength) {
                lowestLength = right - left + 1;
                bestLeft = left;
                bestRight = right;
            }
            while (matchedChars == t.size() && left < right) {
                count[s[left]]++;
                if (count[s[left]] > 0) {
                    matchedChars--;
                }
                left++;
                if (matchedChars == t.size() &&
                    right - left + 1 <= lowestLength) {
                    lowestLength = right - left + 1;
                    bestLeft = left;
                    bestRight = right;
                }
            }
            right++;
        }

        if (bestLeft == -1) {
            return "";
        }
        return s.substr(bestLeft, bestRight - bestLeft + 1);
    }
};
