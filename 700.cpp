//
// Created by pzz on 2021/11/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

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
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr)
            return nullptr;

        if (root->val == val) {
            return root;
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }

        return nullptr;
    }
};

class Solution2 {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root != nullptr) {
            if (root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};

int main() {

}