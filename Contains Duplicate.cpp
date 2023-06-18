#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> found;
        for (int x : nums) {
            if (found.count(x)) {
                return true;
            }
            found.insert(x);
        }
        return false;
    }
};
