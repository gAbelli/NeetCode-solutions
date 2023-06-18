#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        if (!root) {
            return res;
        }
        std::queue<std::pair<TreeNode *, int>> queue;
        queue.push({root, 0});
        int current_level = -1;
        while (!queue.empty()) {
            std::pair<TreeNode *, int> front = queue.front();
            queue.pop();
            if (front.second == current_level) {
                res.back().push_back(front.first->val);
            } else {
                current_level = front.second;
                res.push_back(std::vector<int>{front.first->val});
            }
            if (front.first->left) {
                queue.push({front.first->left, current_level + 1});
            }
            if (front.first->right) {
                queue.push({front.first->right, current_level + 1});
            }
        }
        return res;
    }
};
