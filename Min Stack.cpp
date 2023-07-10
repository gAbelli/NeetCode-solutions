#include <iostream>
#include <vector>

class MinStack {
  public:
    MinStack() {}

    void push(int val) {
        stack.push_back(val);
        if (mins.empty() || val <= mins.back()) {
            mins.push_back(val);
        }
    }

    void pop() {
        int val = stack.back();
        stack.pop_back();
        if (val == mins.back()) {
            mins.pop_back();
        }
    }

    int top() { return stack.back(); }

    int getMin() { return mins.back(); }

  private:
    std::vector<int> stack;
    std::vector<int> mins;
};

int main() {
    MinStack m;

    m.push(1);
    m.getMin();
    // m.top();
    // m.pop();
}
