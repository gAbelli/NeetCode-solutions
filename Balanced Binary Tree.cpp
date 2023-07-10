#include <iostream>

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
    bool isBalanced(TreeNode *root) {
        std::pair<int, bool> pair = helper(root);
        return pair.second;
    }

  private:
    std::pair<int, bool> helper(TreeNode *root) {
        if (!root) {
            return {0, true};
        }

        std::pair<int, int> leftPair = helper(root->left);
        int leftHeight = leftPair.first;
        int leftBalanced = leftPair.second;
        if (!leftBalanced) {
            return {-1, false};
        }

        std::pair<int, int> rightPair = helper(root->right);
        int rightHeight = rightPair.first;
        int rightBalanced = rightPair.second;
        if (!rightBalanced) {
            return {-1, false};
        }

        if (abs(rightHeight - leftHeight) > 1) {
            return {-1, false};
        }

        return {1 + std::max(leftHeight, rightHeight), true};
    }
};
