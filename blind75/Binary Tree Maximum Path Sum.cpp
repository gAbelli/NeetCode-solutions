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
    std::pair<int, int> helper(TreeNode *root) {
        if (!root) {
            return {INT_MIN, INT_MIN};
        }
        std::pair<int, int> left_pair = helper(root->left);
        std::pair<int, int> right_pair = helper(root->right);
        int extensible_max = std::max({root->val, root->val + left_pair.second,
                                       root->val + right_pair.second});
        int global_max = std::max(
            {extensible_max, root->val + left_pair.second + right_pair.second,
             left_pair.first, right_pair.first});
        return {global_max, extensible_max};
    }

    int maxPathSum(TreeNode *root) { return helper(root).first; }
};
