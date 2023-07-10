#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::vector<int> minStack;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!minStack.empty() &&
                   temperatures[i] > temperatures[minStack.back()]) {
                res[minStack.back()] = i - minStack.back();
                minStack.pop_back();
            }
            minStack.push_back(i);
        }

        return res;
    }
};
