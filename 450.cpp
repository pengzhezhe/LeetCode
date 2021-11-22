//
// Created by pzz on 2021/11/22.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return root;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            if (root->left == nullptr && root->right != nullptr) {
                return root->right;
            }

            if (root->left != nullptr && root->right == nullptr) {
                return root->left;
            }

            TreeNode *cur = root->right;

            while (cur->left != nullptr) {
                cur = cur->left;
            }
            cur->left = root->left;

            return root->right;

        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        if (key > root->val)
        root->right = deleteNode(root->right, key);

        return root;
    }
};

int main() {
    return 0;
}