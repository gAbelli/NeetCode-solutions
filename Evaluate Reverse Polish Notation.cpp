#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::vector<int> stack;

        for (const auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = stack.back();
                stack.pop_back();
                int left = stack.back();
                stack.pop_back();
                int res;
                if (token == "+") {
                    res = left + right;
                } else if (token == "-") {
                    res = left - right;
                } else if (token == "*") {
                    res = left * right;
                } else {
                    res = left / right;
                }
                stack.push_back(res);
            } else {
                stack.push_back(std::stoi(token));
            }
        }

        return stack.back();
    }
};
