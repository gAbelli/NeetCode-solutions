#include <iostream>
#include <vector>

class Solution {
  private:
    void helper(std::vector<std::string> &res, int open, int closed,
                std::vector<char> &stack) {
        if (open == 0 && closed == 0) {
            std::string s(stack.begin(), stack.end());
            res.push_back(s);
            return;
        }

        if (open > 0) {
            stack.push_back('(');
            helper(res, open - 1, closed, stack);
            stack.pop_back();
        }

        if (closed > open) {
            stack.push_back(')');
            helper(res, open, closed - 1, stack);
            stack.pop_back();
        }
    }

  public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::vector<char> stack;
        helper(res, n, n, stack);
        return res;
    }
};
