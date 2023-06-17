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
    void inorder(TreeNode *root, int &count, int &res) {
        if (!root) {
            return;
        }
        inorder(root->left, count, res);
        count--;
        if (count < 0) {
            return;
        }
        if (count == 0) {
            res = root->val;
            return;
        }
        inorder(root->right, count, res);
    }

    int kthSmallest(TreeNode *root, int k) {
        int res;
        inorder(root, k, res);
        return res;
    }
};
