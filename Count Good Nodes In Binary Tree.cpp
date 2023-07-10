#include <iostream>
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
    int goodNodes(TreeNode *root) {
        int res = 0;
        helper(root, root->val, res);
        return res;
    }

  private:
    void helper(TreeNode *root, int maxInPath, int &res) {
        if (!root) {
            return;
        }
        if (root->val >= maxInPath) {
            res++;
        }
        helper(root->left, std::max(maxInPath, root->val), res);
        helper(root->right, std::max(maxInPath, root->val), res);
    }
};
