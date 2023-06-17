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
    std::tuple<int, int, bool> helper(TreeNode *root) {
        if (!root) {
            return {INT_MAX, INT_MIN, true};
        }
        std::tuple<int, int, bool> tuple_left = helper(root->left);
        if (!std::get<2>(tuple_left)) {
            return {0, 0, false};
        }
        std::tuple<int, int, bool> tuple_right = helper(root->right);
        if (!std::get<2>(tuple_right)) {
            return {0, 0, false};
        }
        if (!(root->val > std::get<1>(tuple_left) &&
              root->val < std::get<0>(tuple_right))) {
            return {0, 0, false};
        }
        return {std::min(root->val, std::get<0>(tuple_left)),
                std::max(root->val, std::get<1>(tuple_right)), true};
    }

    bool isValidBST(TreeNode *root) {
        auto res = helper(root);
        return std::get<2>(res);
    }
};
