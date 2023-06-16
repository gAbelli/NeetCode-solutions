#include <iostream>

class Solution {
  public:
    int count[26];

    int characterReplacement(std::string s, int k) {
        std::fill(count, count + 26, 0);
        int left = 0;
        int max_count = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'A']++;
            max_count = std::max(max_count, count[s[right] - 'A']);
            if (right - left + 1 - max_count > k) {
                count[s[left] - 'A']--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
