#include <iostream>
#include <sstream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Codec {
  public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root) {
        std::ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data) {
        std::istringstream in(data);
        return decode(in);
    }

    void encode(TreeNode *root, std::ostringstream &out) {
        if (!root) {
            out << "N ";
            return;
        }
        out << root->val << ' ';
        encode(root->left, out);
        encode(root->right, out);
    }

    TreeNode *decode(std::istringstream &in) {
        std::string val = "";
        in >> val;

        if (val == "N") {
            return nullptr;
        }

        TreeNode *root = new TreeNode(std::stoi(val));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }
};
