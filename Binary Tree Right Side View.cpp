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
    std::vector<int> rightSideView(TreeNode *root) {
        std::vector<int> res;
        if (!root) {
            return res;
        }
        std::queue<std::pair<TreeNode *, int>> queue;
        queue.push({root, 0});

        while (!queue.empty()) {
            std::pair<TreeNode *, int> pair = queue.front();
            queue.pop();
            if (pair.first->left) {
                queue.push({pair.first->left, pair.second + 1});
            }
            if (pair.first->right) {
                queue.push({pair.first->right, pair.second + 1});
            }
            if (queue.empty() || queue.front().second > pair.second) {
                res.push_back(pair.first->val);
            }
        }

        return res;
    }
};
