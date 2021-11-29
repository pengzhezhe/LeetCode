//
// Created by pzz on 2021/11/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int pre = 0;
public:
    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr)
            return nullptr;

        //Right
        if (root->right != nullptr)
            convertBST(root->right);

        //Middle
        root->val += pre;
        pre = root->val;

        //Left
        if (root->left != nullptr)
            convertBST(root->left);

        return root;
    }
};

int main() {
    return 0;
}