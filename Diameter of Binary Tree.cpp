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
    int diameterOfBinaryTree(TreeNode *root) {
        std::pair<int, int> pair = helper(root);
        return pair.second;
    }

  private:
    std::pair<int, int> helper(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }

        std::pair<int, int> leftPair = helper(root->left);
        int leftHeight = leftPair.first;
        int leftDiameter = leftPair.second;

        std::pair<int, int> rightPair = helper(root->right);
        int rightHeight = rightPair.first;
        int rightDiameter = rightPair.second;

        return {
            1 + std::max(leftHeight, rightHeight),
            std::max({leftDiameter, rightDiameter, leftHeight + rightHeight})};
    }
};
