#include <iostream>
#include <vector>

class Solution {
  public:
    bool isValid(std::string s) {
        std::vector<char> stack;
        for (const char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.back();
                stack.pop_back();
                if (top == '(' && c != ')') {
                    return false;
                } else if (top == '[' && c != ']') {
                    return false;
                } else if (top == '{' && c != '}') {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
