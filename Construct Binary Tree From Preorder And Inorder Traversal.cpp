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
    TreeNode *helper(std::vector<int> &preorder, std::vector<int> &inorder,
                     int preorder_start, int inorder_start, int len) {
        if (len == 0) {
            return nullptr;
        }
        int root_val = preorder[preorder_start];
        int left_len = 0;
        for (int i = inorder_start;; ++i) {
            if (inorder[i] == root_val) {
                left_len = i - inorder_start;
                break;
            }
        }

        TreeNode *root = new TreeNode(root_val);
        root->left = helper(preorder, inorder, preorder_start + 1,
                            inorder_start, left_len);
        root->right = helper(preorder, inorder, preorder_start + 1 + left_len,
                             inorder_start + left_len + 1, len - left_len - 1);
        return root;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        return helper(preorder, inorder, 0, 0, preorder.size());
    }
};
