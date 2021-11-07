//
// Created by pzz on 2021/11/7.
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
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preOrderTraversal(root, result);
        return result;
    }

    void preOrderTraversal(TreeNode *root, vector<int> &result) {
        if (root == nullptr)
            return;
        result.push_back(root->val);
        preOrderTraversal(root->left,result);
        preOrderTraversal(root->right,result);
    }
};

int main() {
    return 0;
}